package server.repositories.row_mappers;

import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;

import common.entities.GenreEnum;
import common.entities.Movie;

public class MovieRowMapper implements RowMapper<Movie>
{
    @Override
    public Movie mapRow(ResultSet rs, int rowNum) throws SQLException
    {
        Movie movie = new Movie(
                rs.getLong("id"),
                rs.getString("title"),
                GenreEnum.valueOf(rs.getString("genre").toUpperCase()),
                rs.getInt("year")
        );

        return movie;
    }
}
