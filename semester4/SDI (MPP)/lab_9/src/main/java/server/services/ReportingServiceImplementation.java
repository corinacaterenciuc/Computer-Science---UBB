package server.services;

import common.entities.*;
import common.services.ReportingService;
import javafx.util.Pair;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import server.repositories.base.Repository;

import java.time.LocalDate;
import java.time.Period;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

@Component
public class ReportingServiceImplementation implements ReportingService
{
    private final Repository<Long, Rental> rentalRepository;

    private final Repository<Long, Client> clientRepository;

    private final Repository<Long, Movie> movieRepository;

    @Autowired
    public ReportingServiceImplementation(Repository<Long, Client> clientRepository, Repository<Long, Movie> movieRepository, Repository<Long, Rental> rentalRepository)
    {
        this.rentalRepository = rentalRepository;
        this.clientRepository = clientRepository;
        this.movieRepository = movieRepository;
    }

    public List<Pair<Client, Integer>> getTopClients(int limit)
    {
        Iterable<Rental> rentals = rentalRepository.getAll();
        Iterable<Long> clientIds = StreamSupport.stream(clientRepository.getAll().spliterator(), false)
                .map(BaseEntity::getId).collect(Collectors.toList());

        // Count rentals
        Map<Long, Integer> countRentals = new HashMap<>();
        for(Long id: clientIds)
        {
            int clientCount = Math.toIntExact(StreamSupport.stream(rentals.spliterator(), false)
                    .filter(rental -> rental.getClientID().equals(id))
                    .count());
            countRentals.put(id, clientCount);
        }

        // Sort
        List<Map.Entry<Long, Integer>> entries = new ArrayList<>(countRentals.entrySet());
        entries.sort(Map.Entry.comparingByValue(Collections.reverseOrder()));

        // Return top `limit` pairs
        return entries.stream().map(entry -> new Pair<>(
                clientRepository.find(entry.getKey()).orElseThrow(RuntimeException::new),
                entry.getValue()))
                .limit(limit)
                .collect(Collectors.toList());
    }

    public List<Client> getBadRenters()
    {
        Set<Long> badRenterIds = StreamSupport.stream(rentalRepository.getAll().spliterator(), false)
                .filter(rental -> {
                    LocalDate startDate = rental.getStartDate();
                    LocalDate endDate = (rental.getEndDate() == null) ? LocalDate.now() : rental.getEndDate();

                    Period diff = Period.between(startDate, endDate);
                    return diff.getMonths() >= 1;
                })
                .map(Rental::getClientID)
                .collect(Collectors.toSet());
        return StreamSupport.stream(clientRepository.getAll().spliterator(), false)
                .filter(client -> badRenterIds.contains(client.getId()))
                .collect(Collectors.toList());
    }

    public List<Pair<GenreEnum, Integer>> getRentalsByGenre()
    {
        Map<GenreEnum, Integer> countRentals = new HashMap<>();
        rentalRepository.getAll().forEach(rental -> {
            GenreEnum genre = movieRepository.find(rental.getMovieID()).orElseThrow(RuntimeException::new).getGenre();
            countRentals.computeIfPresent(genre, (k, v) -> v+1);
            countRentals.putIfAbsent(genre, 1);
        });
        return countRentals.entrySet().stream()
                .map(entry -> new Pair<>(entry.getKey(), entry.getValue()))
                .collect(Collectors.toList());
    }
}
