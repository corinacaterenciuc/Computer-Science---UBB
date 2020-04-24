package client;

import client.ui.Console;
import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan(basePackages = {"common", "client"})
@EnableAutoConfiguration
public class Client
{
    public static void main(String[] args)
    {
        ConfigurableApplicationContext context = new SpringApplicationBuilder(Client.class).web(WebApplicationType.NONE).run(args);
        Console console = (Console) context.getBean("console");
        console.start();
    }
}
