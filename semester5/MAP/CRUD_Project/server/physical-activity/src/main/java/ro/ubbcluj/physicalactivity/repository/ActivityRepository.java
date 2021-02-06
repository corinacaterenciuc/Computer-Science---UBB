package ro.ubbcluj.physicalactivity.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import ro.ubbcluj.physicalactivity.model.Activity;

@Repository
public interface ActivityRepository extends JpaRepository<Activity, Long> {
}
