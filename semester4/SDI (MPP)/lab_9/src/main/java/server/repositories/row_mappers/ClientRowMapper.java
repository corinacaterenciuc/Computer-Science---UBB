package server.repositories.row_mappers;

import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;

import common.entities.Client;

public class ClientRowMapper implements RowMapper<Client>
{
    @Override
    public Client mapRow(ResultSet rs, int rowNum) throws SQLException
    {
        Client client = new Client(
                rs.getLong("id"),
                rs.getString("name"),
                rs.getString("address")
        );

        return client;
    }
}
