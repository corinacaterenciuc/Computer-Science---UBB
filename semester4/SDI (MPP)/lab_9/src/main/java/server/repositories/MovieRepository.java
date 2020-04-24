package server.repositories;

//import org.springframework.stereotype.Repository;
//
//import java.sql.Connection;
//import java.sql.PreparedStatement;
//import java.sql.SQLException;

import common.entities.Movie;
//import server.repositories.base.DBRepository;
//import server.repositories.row_mappers.MovieRowMapper;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository("movieRepository")
public class MovieRepository extends JpaRepository<Movie, Long> {}
        /*DBRepository<Movie>
{
    public MovieRepository()
    {
        super(new MovieRowMapper());
    }

    @Override
    protected String getAllSQL()
    {
        return "SELECT * FROM MOVIE";
    }

    @Override
    protected String findSQL()
    {
        return "SELECT * FROM MOVIE WHERE id = ?";
    }

    @Override
    protected PreparedStatement saveStatement(Connection con, Movie movie) throws SQLException
    {
        String sql = "INSERT INTO MOVIE (title, genre, year) VALUES (?, ?, ?)";

        PreparedStatement statement = con.prepareStatement(sql);
        statement.setString(1, movie.getTitle());
        statement.setString(2, movie.getGenre().toString());
        statement.setInt(3, movie.getYear());

        return statement;
    }

    @Override
    protected PreparedStatement deleteStatement(Connection con, Long id) throws SQLException
    {
        String sql = "DELETE FROM MOVIE WHERE id = ?";

        PreparedStatement statement = con.prepareStatement(sql);
        statement.setLong(1, id);

        return statement;
    }

    @Override
    protected PreparedStatement updateStatement(Connection con, Movie movie) throws SQLException
    {
        String sql = "UPDATE MOVIE SET title=?, genre=?, year=? WHERE id = ?";

        PreparedStatement statement = con.prepareStatement(sql);
        statement.setString(1, movie.getTitle());
        statement.setString(2, movie.getGenre().toString());
        statement.setInt(3, movie.getYear());
        statement.setLong(4, movie.getId());

        return statement;
    }
}
*/

