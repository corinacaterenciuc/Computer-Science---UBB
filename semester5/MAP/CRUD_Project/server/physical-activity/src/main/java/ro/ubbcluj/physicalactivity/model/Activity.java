package ro.ubbcluj.physicalactivity.model;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.GeneratedValue;

@Entity
public class Activity {
    @Id
    @GeneratedValue
    private Long id;

    private String title;

    private String type;

    private String date;

    private String startTime;

    private String duration;

    private String intensity;

    private String distance;

    private String description;

    public Long getId() {
        return  id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setType(String type) {
        this.type = type;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public void setStartTime(String startTime) {
        this.startTime = startTime;
    }

    public void setDuration(String duration) {
        this.duration = duration;
    }

    public void setIntensity(String intensity) {
        this.intensity = intensity;
    }

    public void setDistance(String distance) {
        this.distance = distance;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getTitle() {
        return title;
    }

    public String getType() {
        return type;
    }

    public String getDate() {
        return date;
    }

    public String getStartTime() {
        return startTime;
    }

    public String getDuration() {
        return duration;
    }

    public String getIntensity() {
        return intensity;
    }

    public String getDistance() {
        return distance;
    }

    public String getDescription() {
        return description;
    }

    @Override
    public String toString() {
        return "Activity{" +
                "id=" + id +
                ", title='" + title + '\'' +
                ", type='" + type + '\'' +
                ", date='" + date + '\'' +
                ", startTime='" + startTime + '\'' +
                ", duration='" + duration + '\'' +
                ", intensity='" + intensity + '\'' +
                ", distance='" + distance + '\'' +
                ", description='" + description + '\'' +
                '}';
    }
}