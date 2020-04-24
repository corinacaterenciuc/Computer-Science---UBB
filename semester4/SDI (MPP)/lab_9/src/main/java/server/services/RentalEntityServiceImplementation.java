package server.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.data.jpa.repository.JpaRepository;


import server.services.base.EntityServiceImplementation;
import common.services.behaviours.filter.FilterBehaviour;
import common.services.behaviours.sort.SortBehaviour;
//import server.repositories.base.Repository;
import common.entities.Rental;

@Component
public class RentalEntityServiceImplementation extends EntityServiceImplementation<Rental>
{
    @Autowired
    public RentalEntityServiceImplementation(
            FilterBehaviour filtering,
            SortBehaviour sorting,
            JpaRepository<Rental, Long> repository)
    {
        super(filtering, sorting, repository);
    }
}