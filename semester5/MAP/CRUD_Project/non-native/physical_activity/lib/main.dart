import 'package:flutter/material.dart';
import 'package:get_it/get_it.dart';
import 'package:physical_activity/details.dart';
import 'package:physical_activity/domain/activity.dart';

import 'add.dart';
import 'domain/repository.dart';

GetIt data = GetIt.instance;

/// main function
void main() {
  data.registerSingleton<Repository>(Repository());
  runApp(PhysicalActivity());
}

/// App Class
class PhysicalActivity extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Physical Activity',
      home: ListAllActivities(),
    );
  }
}

class ListAllActivities extends StatefulWidget {
  @override
  _ListAllActivitiesState createState() => _ListAllActivitiesState();
}

class _ListAllActivitiesState extends State<ListAllActivities> {

  List activities = new List<Activity>();
  Widget _appBarTitle = new Text( 'Activity log: ' );

  /// on init
  @override
  void initState() {
    this._getActivities();
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: _buildBar(context),
      body: new Container(
        alignment: Alignment.center,
        child: _buildList(),
      ),
      bottomNavigationBar: _buildAddButton(),
      resizeToAvoidBottomPadding: false,
    );
  }

  /// method to build the bar widget
  Widget _buildBar(BuildContext context) {
    return new AppBar(
      backgroundColor: Colors.cyanAccent,
      //centerTitle: true,
      title: _appBarTitle,
      leading: Container(
        color: Colors.cyanAccent,
      ),
      //actions: [_buildAddButton(),],
    );
  }

  /// method to build the button widget
  Widget _buildAddButton() {
    return new FlatButton.icon(
      onPressed: () {
        Navigator.push( context,
          MaterialPageRoute(builder: (context) => Add()),
        );
      },
      color: Colors.pinkAccent,
      padding: EdgeInsets.all(10.0),
      icon: Icon(Icons.add),
      label: Text("Add activity"),
      textTheme: ButtonTextTheme.normal,
    );
  }



  /// method to build the list widget
  Widget _buildList() {
    return ListView.builder(
      itemCount: activities.length,
      itemBuilder: (BuildContext context, int index) {
        return Card(
          child: ListTile(
            title: Text(activities[index].title + "\n\n" + " " + activities[index].type + " "*30 + activities[index].date),
            onTap: () => Navigator.pushReplacement( context,
              MaterialPageRoute(builder: (context) => Details(activity: activities[index])),
            ),
          ),
        );
      },
    );
  }

  /// initialize the list
  void _getActivities() async {
    setState(() {
      activities = data.get<Repository>().getAllActivities();
    });
  }
}
