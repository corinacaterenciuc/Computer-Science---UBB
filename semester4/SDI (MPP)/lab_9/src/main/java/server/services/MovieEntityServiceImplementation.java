package server.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import server.services.base.EntityServiceImplementation;
import common.services.behaviours.filter.FilterBehaviour;
import common.services.behaviours.sort.SortBehaviour;
import server.repositories.base.Repository;
import common.entities.Movie;

@Component
public class MovieEntityServiceImplementation extends EntityServiceImplementation<Movie>
{
    @Autowired
    public MovieEntityServiceImplementation(
            FilterBehaviour filtering,
            SortBehaviour sorting,
            Repository<Long, Movie> repository)
    {
        super(filtering, sorting, repository);
    }
}
