package server.repositories.base;

import common.entities.BaseEntity;

import java.util.Optional;


public interface Repository<ID, T extends BaseEntity<ID>>
{
    Optional<T> find(ID id);

    Iterable<T> getAll();

    Optional<T> save(T entity);

    Optional<T> delete(ID id);

    Optional<T> update(T entity);
}
