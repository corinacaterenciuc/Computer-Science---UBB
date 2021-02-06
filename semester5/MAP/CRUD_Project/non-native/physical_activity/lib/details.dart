

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:physical_activity/domain/activity.dart';
import 'package:physical_activity/main.dart';

import 'domain/repository.dart';
import 'edit.dart';

class Details extends StatelessWidget {
  final Activity activity;
  Details({Key key, @required this.activity}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Activity details',
      home: ActivityDetails(activity),
    );
  }
}

class ActivityDetails extends StatefulWidget {

  final Activity activity;
  ActivityDetails(this.activity);

  @override
  _ActivityDetailsState createState() => _ActivityDetailsState(activity);
}

class _ActivityDetailsState extends State<ActivityDetails> {

  final Activity activity;
  _ActivityDetailsState(this.activity);


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
      body: new Container(
        //color: Colors.cyanAccent,
        child: Column(
            mainAxisAlignment: MainAxisAlignment.start,
            crossAxisAlignment: CrossAxisAlignment.stretch,
          children: <Widget>[
            Row (
              mainAxisAlignment: MainAxisAlignment.spaceAround,
              crossAxisAlignment: CrossAxisAlignment.baseline,
              children: <Widget>[
                _buildType(),
                _buildDate(),
              ],
            ),
            Row (
              mainAxisAlignment: MainAxisAlignment.spaceAround,
              crossAxisAlignment: CrossAxisAlignment.baseline,
              children: <Widget>[
                _buildStartTime(),
                _buildDuration(),
              ],
            ),
            Row (
              mainAxisAlignment: MainAxisAlignment.spaceAround,
              crossAxisAlignment: CrossAxisAlignment.baseline,
              children: <Widget>[
                _buildIntensity(),
                _buildDistance(),
              ],
            ),
            Padding(
                padding: EdgeInsets.all(
                     10.0),
              child: _buildDescription(),
            )

          ]
        ),
      ),
      bottomNavigationBar: _buildDetailsButtons(),
    );
  }

  Widget _buildType() {
    return Padding(
      padding: EdgeInsets.all(10.0),
      child: Center(
        child: Container(
          color: Colors.pinkAccent,
          width: 100,
          height: 50,
          child: Column(
              children: [
                Text (
                  "Type: ",
                  textAlign: TextAlign.start,
                ),
                FittedBox(
                  fit: BoxFit.cover,
                  child: new Text(
                    activity.type,
                    textAlign: TextAlign.center,
                    style: new TextStyle(
                      fontSize: 20.0,
                      color: Colors.black,
                    ),
                  ),
                ),
              ]
          ),
        ),
      ),
    );
  }

  Widget _buildDate() {
    return Padding(
      padding: EdgeInsets.all(10.0),
      child: Center(
        child: Container(
            color: Colors.pinkAccent,
            width: 100,
            height: 50,
            child: Column(
              children: [
                Text (
                    "Date: ",
                  textAlign: TextAlign.start,
                ),
                FittedBox(
                  fit: BoxFit.cover,
                  child: new Text(
                     activity.date,
                    textAlign: TextAlign.center,
                    style: new TextStyle(
                      fontSize: 20.0,
                      color: Colors.black,
                    ),
                ),
              ),
            ]
            ),
        ),
      ),
    );
  }

  Widget _buildStartTime(){
    return Padding(
      padding: EdgeInsets.all(10.0),
      child: Center(
        child: Container(
          color: Colors.pinkAccent,
          width: 100,
          height: 50,
          child: Column(
              children: [
                Text (
                  "Start time: ",
                  textAlign: TextAlign.start,
                ),
                FittedBox(
                  fit: BoxFit.cover,
                  child: new Text(
                    activity.startTime,
                    textAlign: TextAlign.center,
                    style: new TextStyle(
                      fontSize: 20.0,
                      color: Colors.black,
                    ),
                  ),
                ),
              ]
          ),
        ),
      ),
    );
  }

  Widget _buildDuration() {
    return Padding(
      padding: EdgeInsets.all(10.0),
      child: Center(
        child: Container(
          color: Colors.pinkAccent,
          width: 100,
          height: 50,
          child: Column(
              children: [
                Text (
                  "Duration: ",
                  textAlign: TextAlign.start,
                ),
                FittedBox(
                  fit: BoxFit.cover,
                  child: new Text(
                    activity.duration,
                    textAlign: TextAlign.center,
                    style: new TextStyle(
                      fontSize: 20.0,
                      color: Colors.black,
                    ),
                  ),
                ),
              ]
          ),
        ),
      ),
    );
  }

  Widget _buildIntensity() {
    return Padding(
      padding: EdgeInsets.all(10.0),
      child: Center(
        child: Container(
          color: Colors.pinkAccent,
          width: 100,
          height: 50,
          child: Column(
              children: [
                Text (
                  "Intensity: ",
                  textAlign: TextAlign.start,
                ),
                FittedBox(
                  fit: BoxFit.cover,
                  child: new Text(
                    activity.intensity,
                    textAlign: TextAlign.center,
                    style: new TextStyle(
                      fontSize: 20.0,
                      color: Colors.black,
                    ),
                  ),
                ),
              ]
          ),
        ),
      ),
    );
  }

  Widget _buildDistance() {
    return Padding(
      padding: EdgeInsets.all(10.0),
      child: Center(
        child: Container(
          color: Colors.pinkAccent,
          width: 100,
          height: 50,
          child: Column(
              children: [
                Text (
                  "Distance: ",
                  textAlign: TextAlign.start,
                ),
                FittedBox(
                  fit: BoxFit.cover,
                  child: new Text(
                    activity.distance,
                    textAlign: TextAlign.center,
                    style: new TextStyle(
                      fontSize: 20.0,
                      color: Colors.black,
                    ),
                  ),
                ),
              ]
          ),
        ),
      ),
    );
  }

  Widget _buildDescription() {
    return Padding(
      padding: EdgeInsets.only(top: 10.0),
      child: Center(
        child: Container(
          color: Colors.pinkAccent,
          width: 500,
          height: 50,
          child: Column(
              children: [
                Text (
                  "Description: ",
                  textAlign: TextAlign.left,
                ),
                FittedBox(
                  fit: BoxFit.cover,
                  child: new Text(
                    activity.description,
                    textAlign: TextAlign.left,
                    style: new TextStyle(
                      fontSize: 20.0,
                      color: Colors.black,
                    ),
                  ),
                ),
              ]
          ),
        ),
      ),
    );
  }

  Widget _buildDetailsButtons() {
    return Padding(
      padding: EdgeInsets.all(20.0),
      child: Row (
          children: [
            Padding(
              padding: EdgeInsets.all(10.0),
              child: FlatButton.icon(
                onPressed: () {
                  // Navigator.pop(context);
                  Navigator.pushReplacement(context,
                    MaterialPageRoute(builder: (context) => PhysicalActivity()),
                  );
                },
                color: Colors.pinkAccent,
                padding: EdgeInsets.all(10.0),
                icon: Icon(Icons.list),
                label: Text("Back"),
                textTheme: ButtonTextTheme.normal,
              ),
            ),
            FlatButton.icon(
              onPressed: () {
                Navigator.pushReplacement(context,
                  MaterialPageRoute(builder: (context) => (Edit(activity: activity))),
                );
              },
              color: Colors.pinkAccent,
              padding: EdgeInsets.all(10.0),
              icon: Icon(Icons.edit),
              label: Text("Edit"),
              textTheme: ButtonTextTheme.normal,
            ),
            Padding(
              padding: EdgeInsets.only(
                  left: 10.0),
              child: FlatButton.icon(
                onPressed: () {
                  showAlertDialog(context, activity);
                },
                color: Colors.pinkAccent,
                padding: EdgeInsets.all(10.0),
                icon: Icon(Icons.delete),
                label: Text("Delete"),
                textTheme: ButtonTextTheme.normal,
              ),

            ),

          ]
      ),
    );
  }

}

showAlertDialog(BuildContext context, Activity activity) {
  // set up the buttons
  Widget cancelButton = FlatButton(
    child: Text("Cancel"),
    onPressed:  () {
      Navigator.of(context, rootNavigator: true).pop(); // dismiss dialog
    },
  );
  Widget yesButton = FlatButton(
    child: Text("Yes"),
    onPressed:  () {
      data.get<Repository>().removeActivity(activity.id);
      Navigator.of(context, rootNavigator: true).pop(); // dismiss dialog
      Navigator.pushReplacement(context,
        MaterialPageRoute(builder: (context) => PhysicalActivity()),
      );
    },
  );
  // set up the AlertDialog
  AlertDialog alert = AlertDialog(
    content: Text("Are you sure you want to delete the activity?"),
    actions: [
      cancelButton,
      yesButton,
    ],
  );
  // show the dialog
  showDialog(
    context: context,
    builder: (BuildContext context) {
      return alert;
    },
  );
}
