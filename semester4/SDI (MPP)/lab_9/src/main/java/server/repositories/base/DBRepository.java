package server.repositories.base;

import common.entities.BaseEntity;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcOperations;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.jdbc.support.GeneratedKeyHolder;
import org.springframework.jdbc.support.KeyHolder;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Optional;

public abstract class DBRepository<T extends BaseEntity<Long>> implements Repository<Long, T>
{
    @Autowired
    private JdbcOperations jdbcOperations;

    private RowMapper<T> rowMapper;

    protected abstract String getAllSQL();

    protected abstract String findSQL();

    protected abstract PreparedStatement saveStatement(Connection con, T entity) throws SQLException;

    protected abstract PreparedStatement deleteStatement(Connection con, Long id) throws SQLException;

    protected abstract PreparedStatement updateStatement(Connection con, T entity) throws SQLException;

    protected DBRepository(RowMapper<T> rowMapper)
    {
        this.rowMapper = rowMapper;
    }

    @Override
    public Iterable<T> getAll()
    {
        return jdbcOperations.query(
                getAllSQL(),
                rowMapper
        );
    }

    @Override
    public Optional<T> find(Long id)
    {
        var entity = jdbcOperations.queryForObject(
                findSQL(),
                new Object[]{id},
                rowMapper
        );

        return Optional.ofNullable(entity);
    }

    @Override
    public Optional<T> save(T entity)
    {
        KeyHolder keyHolder = new GeneratedKeyHolder();

        jdbcOperations.update(
                con -> saveStatement(con, entity),
                keyHolder
        );

        return find((Long) keyHolder.getKey());
    }

    public Optional<T> delete(Long id)
    {
        Optional<T> entity = find(id);

        jdbcOperations.update(
                con -> deleteStatement(con, id)
        );

        return entity;
    }

    public Optional<T> update(T entity)
    {
        jdbcOperations.update(
                con -> updateStatement(con, entity)
        );

        return find(entity.getId());
    }

    // testing purposes
    protected void setDataSource(DataSource dataSource) {
        jdbcOperations = new JdbcTemplate(dataSource);
    }
}
