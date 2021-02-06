package ro.korina.physicalactivity

import android.app.AlertDialog
import android.content.Context
import android.content.Intent
import android.database.sqlite.SQLiteDatabase
import android.net.ConnectivityManager
import android.net.Network
import android.net.NetworkCapabilities
import android.os.Bundle
import android.util.Log
import android.view.View
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import kotlinx.android.synthetic.main.activity_main.*
import org.jetbrains.anko.custom.onUiThread
import ro.korina.physicalactivity.db.Utils
import ro.korina.physicalactivity.domain.ActivityAdapter
import ro.korina.physicalactivity.domain.DbRepository
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import ro.korina.physicalactivity.client.ActivityAPI
import ro.korina.physicalactivity.domain.Activity


class MainActivity : AppCompatActivity() {


    private lateinit var readableDb: SQLiteDatabase
    private lateinit var writableDb: SQLiteDatabase
    private lateinit var activities: MutableList<Activity>
    private lateinit var dbHelper: Utils

    private lateinit var activityAdapter: ActivityAdapter

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        dbHelper = Utils(this)
        readableDb = dbHelper.readableDatabase
        writableDb = dbHelper.writableDatabase


        if (isNetworkConnected()) {
            ActivityAPI.retrofitService.retrieveAllActivities().enqueue(object : Callback<List<Activity>> {
                override fun onFailure(call: Call<List<Activity>>, t: Throwable) {
                    Log.d("TAG_TAG", "Failed :" + t.message)
                }
                override fun onResponse(call: Call<List<Activity>>, response: Response<List<Activity>>) {
                    println(response.body().toString())
                    activities = (response.body() as MutableList<Activity>?)!!
                    println(activities.toString())
                    onUiThread{
                        activityAdapter = ActivityAdapter(activities)
                        recyclerView_activities.adapter = activityAdapter
                        recyclerView_activities.layoutManager = LinearLayoutManager(this)
                    }
                }
            })
        } else {
            showDialog()
            activities = DbRepository.getInstance(readableDb,writableDb)?.getAll()!!
            activityAdapter = ActivityAdapter(activities)
            recyclerView_activities.adapter = activityAdapter
            recyclerView_activities.layoutManager = LinearLayoutManager(this)
        }



        button_addActivity.setOnClickListener{ v: View ->
            val intent = Intent(v.context, Add::class.java)
            startActivityForResult(intent, 1)

        }

        val connectivityManager = getSystemService(Context.CONNECTIVITY_SERVICE) as ConnectivityManager
        connectivityManager.registerDefaultNetworkCallback(object : ConnectivityManager.NetworkCallback() {
            override fun onAvailable(network: Network) {
                ActivityAPI.retrofitService.retrieveAllActivities()
                    .enqueue(object : Callback<List<Activity>> {
                        override fun onFailure(call: Call<List<Activity>>, t: Throwable) {
                            Log.d("TAG_TAG", "Failed :" + t.message)
                        }

                        override fun onResponse(call: Call<List<Activity>>, response: Response<List<Activity>>) {
                            val activitiesServer = response.body()!!
                            val activitiesDB = DbRepository.getInstance(readableDb, writableDb)?.getAll()!!
                            for (activity: Activity in activitiesDB) {
                                var itIts = false
                                for (a: Activity in activitiesServer)
                                    if (a.title == activity.title)
                                        itIts = true

                                if (!itIts){
                                    ActivityAPI.retrofitService.createActivity(activity)
                                        .enqueue(object :
                                            Callback<Activity> {
                                            override fun onFailure(
                                                call: Call<Activity>,
                                                t: Throwable
                                            ) {
                                                Log.d("TAG_TAG", "Failed :" + t.message)
                                            }

                                            override fun onResponse(
                                                call: Call<Activity>,
                                                response: Response<Activity>
                                            ) {
                                                Log.d("TAG_TAG", "Success :" + response.body())
                                            }
                                        })
                                }
                            }
                        }
                    })
            }
        })

    }

    private fun update_list(){
        activities.clear()
        if (isNetworkConnected()) {
            ActivityAPI.retrofitService.retrieveAllActivities().enqueue(object : Callback<List<Activity>> {
                override fun onFailure(call: Call<List<Activity>>, t: Throwable) {
                    Log.d("TAG_TAG", "Failed :" + t.message)
                }
                override fun onResponse(call: Call<List<Activity>>, response: Response<List<Activity>>) {
                    println(response.body().toString())
                    activities.addAll((response.body() as MutableList<Activity>?)!!)
                    onUiThread { recyclerView_activities.adapter?.notifyDataSetChanged() }

                }
            })
        } else {
            showDialog()
            activities.addAll(DbRepository.getInstance(readableDb,writableDb)?.getAll()!!)
        }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)
        update_list()

        if (requestCode == 1) {
            if (resultCode == RESULT_OK) {
                recyclerView_activities.adapter?.notifyDataSetChanged()
            }
        }
        if (requestCode == 2) {
            if (resultCode == RESULT_OK) {
                recyclerView_activities.adapter?.notifyDataSetChanged()
            }
        }
    }

    private fun showDialog(){
            AlertDialog.Builder(this).setTitle("No Internet Connection")
                .setMessage("Fallback on local DB")
                .setPositiveButton(android.R.string.ok) { _, _ -> }
                .setIcon(android.R.drawable.ic_dialog_alert).show()
        }
    private fun isNetworkConnected(): Boolean {
            val connectivityManager = getSystemService(Context.CONNECTIVITY_SERVICE) as ConnectivityManager
            val activeNetwork = connectivityManager.activeNetwork
            val networkCapabilities = connectivityManager.getNetworkCapabilities(activeNetwork)
            return networkCapabilities != null &&
                    networkCapabilities.hasCapability(NetworkCapabilities.NET_CAPABILITY_INTERNET)
    }

}