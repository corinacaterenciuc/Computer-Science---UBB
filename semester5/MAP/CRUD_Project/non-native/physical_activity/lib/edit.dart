
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:physical_activity/details.dart';

import 'domain/activity.dart';
import 'domain/repository.dart';
import 'main.dart';

class Edit extends StatelessWidget {

  final Activity activity;
  Edit({Key key, @required this.activity}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Activity edit',
      home: ActivityEdit(activity),
    );
  }
}

class ActivityEdit extends StatefulWidget {

  final Activity activity;
  ActivityEdit(this.activity);

  @override
  _ActivityEditState createState() => _ActivityEditState(activity);
}

class _ActivityEditState extends State<ActivityEdit> {

  final Activity activity;
  _ActivityEditState(this.activity);

  final TextEditingController _title = new TextEditingController();
  final TextEditingController _type = new TextEditingController();
  final TextEditingController _date = new TextEditingController();
  final TextEditingController _startTime = new TextEditingController();
  final TextEditingController _duration = new TextEditingController();
  final TextEditingController _intensity = new TextEditingController();
  final TextEditingController _distance = new TextEditingController();
  final TextEditingController _description = new TextEditingController();

  @override
  void initState() {
    _title.text = activity.title;
    _type.text = activity.type;
    _date.text = activity.date;
    _startTime.text = activity.startTime;
    _duration.text = activity.duration;
    _intensity.text = activity.intensity;
    _distance.text = activity.distance;
    _description.text = activity.description;
    super.initState();
  }

  @override
  Widget build(BuildContext context) {

    return Scaffold(
      appBar: new AppBar(
        centerTitle: false,
        title: Text(
          activity.title,
          style: new TextStyle(
            fontSize: 20.0,
            color: Colors.black,
          ),
        ),
        backgroundColor: Colors.pinkAccent,
      ),
      body: SingleChildScrollView(
        child: Column(
          children: <Widget>[
            Container(
              width: MediaQuery.of(context).size.width,
              height: MediaQuery.of(context).size.height-80,
              child: ListView(
                children: <Widget>[
                  _buildTitle(),
                  _buildType(),
                  _buildDate(),
                  _buildStartTime(),
                  _buildDuration(),
                  _buildIntensity(),
                  _buildDistance(),
                  _buildDescription(),
                  _buildEditButtons(),
                ],
              ),
            ),

          ],
        ),
      ),
    );
  }

  Widget _buildTitle() {
    return Padding(
      padding: EdgeInsets.only(left: 16.0, right: 16.0),
      child: TextField(
        controller: _title,
        decoration: InputDecoration(
          labelText: "Title: ",
          hintText: "enter title",
        ),
      ),
    );
  }

  Widget _buildType() {
    return Padding(
        padding: EdgeInsets.only(left: 16.0, right: 16.0),
        child: TextField(
          controller: _type,
          decoration: InputDecoration(
            labelText: "Type: ",
            hintText: "enter type",
          ),
        ),
    );
  }

  Widget _buildDate() {
    return Padding(
      padding: EdgeInsets.only(left: 16.0, right: 16.0),
      child: TextField(
        controller: _date,
        decoration: InputDecoration(
          labelText: "Date: ",
          hintText: "enter date",
        ),
      ),
    );
  }

  Widget _buildStartTime(){
    return Padding(
      padding: EdgeInsets.only(left: 16.0, right: 16.0),
      child: TextField(
        controller: _startTime,
        decoration: InputDecoration(
          labelText: "Start time: ",
          hintText: "enter start time",
        ),
      ),
    );
  }

  Widget _buildDuration() {
    return Padding(
      padding: EdgeInsets.only(left: 16.0, right: 16.0),
      child: TextField(
        controller: _duration,
        decoration: InputDecoration(
          labelText: "Duration: ",
          hintText: "enter duration",
        ),
      ),
    );
  }

  Widget _buildIntensity() {
    return Padding(
      padding: EdgeInsets.only(left: 16.0, right: 16.0),
      child: TextField(
        controller: _intensity,
        decoration: InputDecoration(
          labelText: "Intensity: ",
          hintText: "enter intensity",
        ),
      ),
    );
  }

  Widget _buildDistance() {
    return Padding(
      padding: EdgeInsets.only(left: 16.0, right: 16.0),
      child: TextField(
        controller: _distance,
        decoration: InputDecoration(
          labelText: "Distance: ",
          hintText: "enter distance",
        ),
      ),
    );

  }

  Widget _buildDescription() {
    return Padding(
      padding: EdgeInsets.only(left: 16.0, right: 16.0),
      child: TextField(
        controller: _description,
        decoration: InputDecoration(
          labelText: "Description: ",
          hintText: "enter description",
        ),
      ),
    );
  }


  Widget _buildEditButtons() {
    return Row (
      mainAxisAlignment: MainAxisAlignment.spaceEvenly,
      children: <Widget>[
        RaisedButton(
          color: Colors.pinkAccent,
            onPressed: () {
              Activity updated_activity = new Activity(activity.id, _title.text, _type.text, _date.text, _startTime.text, _duration.text, _intensity.text, _distance.text, _description.text);
              data.get<Repository>().updateActivity(updated_activity);
              Navigator.pushReplacement(context,
                  MaterialPageRoute(builder: (context) => (Details(activity: updated_activity)))
              );
            },
          child: const Text(
            "Save",
            style: TextStyle(color: Colors.black),
          ),
        ),
        RaisedButton(
          color: Colors.pinkAccent,
          onPressed: () {
            // Navigator.pop(context);
            Navigator.pushReplacement(context,
              MaterialPageRoute(builder: (context) => (Details(activity: activity))),
            );
          },
          child: const Text(
            "Cancel",
            style: TextStyle(color: Colors.black),
          ),
        ),
      ],
    );
  }



}
