package server.repositories.row_mappers;

import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;

import common.entities.Rental;

public class RentalRowMapper implements RowMapper<Rental>
{
    @Override
    public Rental mapRow(ResultSet rs, int rowNum) throws SQLException
    {
        Rental rental = new Rental(
                rs.getLong("id"),
                rs.getLong("client_id"),
                rs.getLong("movie_id"),
                rs.getDate("start_date").toLocalDate()
        );

        if (rs.getDate("end_date") != null)
            rental.returnMovie(rs.getDate("end_date").toLocalDate());

        return rental;
    }
}
