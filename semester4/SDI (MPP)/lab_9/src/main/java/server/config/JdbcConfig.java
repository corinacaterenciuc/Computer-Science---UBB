package server.config;

import org.apache.commons.dbcp2.BasicDataSource;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.jdbc.core.JdbcOperations;
import org.springframework.jdbc.core.JdbcTemplate;

import javax.sql.DataSource;

@Configuration
public class JdbcConfig
{
    @Value("${db.url}")
    private String dbUrl;

    @Bean
    JdbcOperations jdbcOperations()
    {
        return new JdbcTemplate(dataSource());
    }

    @Bean
    DataSource dataSource()
    {
        BasicDataSource basicDataSource = new BasicDataSource();
        basicDataSource.setUrl(dbUrl);

        return basicDataSource;
    }
}
