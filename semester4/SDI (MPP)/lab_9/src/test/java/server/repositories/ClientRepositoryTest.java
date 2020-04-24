package server.repositories;

import common.entities.Client;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseBuilder;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseType;

import javax.sql.DataSource;

public class ClientRepositoryTest
{
    private static ClientRepository clientRepository;

    @Before
    public void setUp() {
        DataSource dataSource = new EmbeddedDatabaseBuilder().setType(EmbeddedDatabaseType.H2)
                .addScript("classpath:sql_scripts/schema.sql")
                .addScript("classpath:test_sql_scripts/test_client_data.sql")
                .build();

        clientRepository = new ClientRepository();
        clientRepository.setDataSource(dataSource);
    }

    @After
    public void tearDown() {
        clientRepository = null;
    }

    @Test
    public void testFind() {
        Client client = clientRepository.find(1L).get();
        assert client.getName().equals("n1");
        assert client.getAddress().equals("a1");
    }

    @Test(expected = RuntimeException.class)
    public void testNotFound() {
        Client client = clientRepository.find(10L).orElseThrow(RuntimeException::new);
    }

    @Test
    public void testSave() {
        Client newClient = new Client("n3", "a3");
        Client savedClient = clientRepository.save(newClient).get();
        assert savedClient.getId() == 3;
    }
}
