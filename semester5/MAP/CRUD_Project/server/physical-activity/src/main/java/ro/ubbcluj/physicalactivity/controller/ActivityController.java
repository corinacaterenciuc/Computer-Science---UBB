package ro.ubbcluj.physicalactivity.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.support.ServletUriComponentsBuilder;
import ro.ubbcluj.physicalactivity.model.Activity;
import ro.ubbcluj.physicalactivity.repository.ActivityRepository;
import ro.ubbcluj.physicalactivity.utils.ActivityNotFoundException;

import java.net.URI;
import java.util.List;
import java.util.Optional;

@RestController
public class ActivityController {

    @Autowired
    private ActivityRepository activity_repository;

    @GetMapping("/activities")
    public List<Activity> retrieveAllActivities() {
        System.out.println("GET ALL");
        return activity_repository.findAll();
    }

    @GetMapping("/activities/{id}")
    public Activity retrieveActivity(@PathVariable long id) throws ActivityNotFoundException {
        System.out.println("GET ONE");
        Optional<Activity> activity = activity_repository.findById(id);

        if (activity.isEmpty())
            throw new ActivityNotFoundException("id-" + id);

        return activity.get();
    }

    @DeleteMapping("/activities/{id}")
    public void deleteActivity(@PathVariable long id) {
        System.out.println("DELETE");
        activity_repository.deleteById(id);
    }

    @PostMapping("/activities")
    public ResponseEntity<Object> createActivity(@RequestBody Activity activity) {
        System.out.println("POST");
        Activity savedActivity = activity_repository.save(activity);

        URI location = ServletUriComponentsBuilder.fromCurrentRequest().path("/{id}")
                .buildAndExpand(savedActivity.getId()).toUri();

        return ResponseEntity.created(location).build();

    }

    @PutMapping("/activities/{id}")
    public ResponseEntity<Object> updateActivity(@RequestBody Activity activity, @PathVariable long id) {
        System.out.println("PUT");
        Optional<Activity> activityOptional = activity_repository.findById(id);

        if (activityOptional.isEmpty())
            return ResponseEntity.notFound().build();

        activity.setId(id);
        activity_repository.save(activity);

        return ResponseEntity.noContent().build();
    }
}