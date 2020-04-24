package server.repositories;

//import org.springframework.stereotype.Repository;
//
//import java.sql.Connection;
//import java.sql.PreparedStatement;
//import java.sql.SQLException;

import common.entities.Client;
//import server.repositories.base.DBRepository;
//import server.repositories.row_mappers.ClientRowMapper;
import org.springFramework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

//import javax.sql.DataSource;


@Repository("clientRepository")
public class ClientRepository extends JpaRepository<Client, Long> {}
        /*DBRepository<Client>
{
    public ClientRepository()
    {
        super(new ClientRowMapper());
    }

    @Override
    protected String getAllSQL()
    {
        return "SELECT * FROM CLIENT";
    }

    @Override
    protected String findSQL()
    {
        return "SELECT * FROM CLIENT WHERE id = ?";
    }

    @Override
    protected PreparedStatement saveStatement(Connection con, Client client) throws SQLException
    {
        String sql = "INSERT INTO CLIENT (name, address) VALUES (?, ?)";

        PreparedStatement statement = con.prepareStatement(sql);
        statement.setString(1, client.getName());
        statement.setString(2, client.getAddress());

        return statement;
    }

    @Override
    protected PreparedStatement deleteStatement(Connection con, Long id) throws SQLException
    {
        String sql = "DELETE FROM CLIENT WHERE id = ?";

        PreparedStatement statement = con.prepareStatement(sql);
        statement.setLong(1, id);

        return statement;
    }

    @Override
    protected PreparedStatement updateStatement(Connection con, Client client) throws SQLException
    {
        String sql = "UPDATE CLIENT SET name=?, address=? WHERE id = ?";

        PreparedStatement statement = con.prepareStatement(sql);
        statement.setString(1, client.getName());
        statement.setString(2, client.getAddress());
        statement.setLong(3, client.getId());

        return statement;
    }

    // testing purposes
    public void setDataSource(DataSource dataSource) {
        super.setDataSource(dataSource);
    }
}
*/