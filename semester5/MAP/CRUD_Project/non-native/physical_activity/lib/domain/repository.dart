import 'activity.dart';

class Repository {
  List<Activity> activities = new List<Activity>();

  Repository(){
    activities = List.of([
      Activity(0,
          "run 1 - Marathon Training",
          "run",
          "12.10.2019",
          "12:30",
          "43 mins",
          "medium",
          "5.5 km",
          "went too fast in the beginning"),

      Activity(1,
          "run 2 - Long run",
          "run",
          "12.10.2019",
          "12:30",
          "80 mins",
          "easy",
          "15 km",
          "idk what was this"),

      Activity(2,
          "plimbare de seara",
          "walk",
          "18.10.2019",
          "18:00",
          "30 min",
          "easy",
          "-",
          "waled with my thoughts"),

      Activity(3,
          "dance",
          "run",
          "23.11.2019",
          "20:11",
          "23 min",
          "medium",
          "-",
          "From Now On by The Greatest Showman"),

      Activity(4,
          "swim1",
          "swim",
          "10.08.2019",
          "12:30",
          "20 min",
          "hard",
          "0.5 km",
          "good swim"
      )
    ]);
  }

  void removeActivity(int id) {
    activities.removeAt(id);
    for (int i = 0; i < activities.length; i++) {
      activities[i].id = i;
    }
  }

  void addActivity(Activity activity) {
    activity.id = activities.length;
    activities.add(activity);
  }

  void updateActivity(Activity activity) {
    for (int i = 0; i < activities.length; i++) {
      if (activities[i].id == activity.id)
        activities[i] = activity;
    }
  }


  List<Activity> getAllActivities() {
    return activities;
  }


}