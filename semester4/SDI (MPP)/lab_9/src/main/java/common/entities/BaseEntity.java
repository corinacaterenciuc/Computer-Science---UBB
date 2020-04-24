package common.entities;

import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.MappedSuperclass;
import java.io.Serializable;

@MappedSuperclass
public abstract class BaseEntity<ID extends Serializable> implements Serializable
{
    @Id
    @GeneratedValues
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
