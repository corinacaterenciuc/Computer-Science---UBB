package common.entities;

import java.io.Serializable;

public abstract class BaseEntity<ID> implements Serializable
{
    private ID id;

    public ID getId()
    {
        return id;
    }

    public void setId(ID id)
    {
        this.id = id;
    }

    @Override
    public String toString()
    {
        return "BaseEntity{" + "id= '" + id + "'}";
    }
}
