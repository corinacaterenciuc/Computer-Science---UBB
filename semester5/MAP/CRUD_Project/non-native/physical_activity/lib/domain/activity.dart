import 'dart:core';
import 'package:dataclass/dataclass.dart';

@dataClass
class Activity {
  int id;
  String title;
  String type;
  String date;
  String startTime = "";
  String duration = "";
  String intensity = "";
  String distance = "";
  String description = "";

  Activity(this.id, this.title, this.type, this.date, this.startTime, this.duration, this.intensity, this.distance, this.description);
}