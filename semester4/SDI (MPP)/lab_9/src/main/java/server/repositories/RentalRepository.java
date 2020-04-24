package server.repositories;

//import org.springframework.stereotype.Repository;
//
//import java.sql.Connection;
//import java.sql.Date;
//import java.sql.PreparedStatement;
//import java.sql.SQLException;

import common.entities.Rental;
//import server.repositories.base.DBRepository;
//import server.repositories.row_mappers.RentalRowMapper;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository("rentalRepository")
public class RentalRepository extends JpaRepository<Rental, Long> {}
        /*DBRepository<Rental>
{
    public RentalRepository()
    {
        super(new RentalRowMapper());
    }

    @Override
    protected String getAllSQL()
    {
        return "SELECT * FROM RENTAL";
    }

    @Override
    protected String findSQL()
    {
        return "SELECT * FROM RENTAL WHERE id = ?";
    }

    @Override
    protected PreparedStatement saveStatement(Connection con, Rental rental) throws SQLException
    {
        String sql = "INSERT INTO RENTAL (client_id, movie_id, start_date, end_date) VALUES (?, ?, ?, ?)";

        return prepareStatement(con, rental, sql);
    }

    @Override
    protected PreparedStatement deleteStatement(Connection con, Long id) throws SQLException
    {
        String sql = "DELETE FROM RENTAL WHERE id = ?";

        PreparedStatement statement = con.prepareStatement(sql);
        statement.setLong(1, id);

        return statement;
    }

    @Override
    protected PreparedStatement updateStatement(Connection con, Rental rental) throws SQLException
    {
        String sql = "UPDATE RENTAL SET client_id=?, movie_id=?, start_date=?, end_date=? WHERE id = ?";

        var statement = prepareStatement(con, rental, sql);
        statement.setLong(5, rental.getId());

        return statement;
    }

    private PreparedStatement prepareStatement(Connection con, Rental rental, String sql) throws SQLException
    {
        PreparedStatement statement = con.prepareStatement(sql);
        statement.setLong(1, rental.getClientID());
        statement.setLong(2, rental.getMovieID());
        statement.setDate(3, Date.valueOf(rental.getStartDate()));
        if (rental.getEndDate() != null)
            statement.setDate(4, Date.valueOf(rental.getEndDate()));
        else
            statement.setDate(4, null);

        return statement;
    }
}
*/