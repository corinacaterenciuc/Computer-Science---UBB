package server.services.base;

import common.entities.BaseEntity;
import common.services.EntityService;
import common.services.behaviours.filter.FilterBehaviour;
import common.services.behaviours.filter.FilterStrategy;
import common.services.behaviours.sort.SortBehaviour;
import common.services.behaviours.sort.SortStrategy;
import server.repositories.base.Repository;

public abstract class EntityServiceImplementation<T extends BaseEntity<Long>> implements EntityService<T>
{
    private final FilterBehaviour filtering;

    private final SortBehaviour sorting;

    private final Repository<Long, T> repository;

    public EntityServiceImplementation(FilterBehaviour filtering, SortBehaviour sorting, Repository<Long, T> repository)
    {
        this.filtering = filtering;
        this.sorting = sorting;
        this.repository = repository;
    }

    @Override
    public T addEntity(T entity)
    {
        return this.repository.save(entity).orElseThrow(RuntimeException::new);
    }

    @Override
    public Iterable<T> getAllEntities(SortStrategy strategy)
    {
        return this.sorting.sort(this.repository.getAll(), strategy);
    }

    @Override
    public T deleteEntity(Long id)
    {
        return this.repository.delete(id).orElseThrow(RuntimeException::new);
    }

    @Override
    public T updateEntity(T updatedEntity)
    {
        return this.repository.update(updatedEntity).orElseThrow(RuntimeException::new);
    }

    @Override
    public Iterable<T> filter(FilterStrategy strategy)
    {
        return this.filtering.filter(this.repository.getAll(), strategy);
    }

    @Override
    public T getEntity(Long id)
    {
        return this.repository.find(id).orElseThrow(RuntimeException::new);
    }
}
