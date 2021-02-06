package ro.korina.physicalactivity

import android.app.AlertDialog
import android.content.Context
import android.content.Intent
import android.database.sqlite.SQLiteDatabase
import android.net.ConnectivityManager
import android.net.NetworkCapabilities
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.EditText
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_edit.*
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import ro.korina.physicalactivity.client.ActivityAPI
import ro.korina.physicalactivity.db.Utils
import ro.korina.physicalactivity.domain.Activity
import ro.korina.physicalactivity.domain.DbRepository

class Edit : AppCompatActivity() {
    private var position: Int = 0

    private lateinit var readableDb: SQLiteDatabase
    private lateinit var writableDb: SQLiteDatabase

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_edit)

        val dbHelper = Utils(this)
        readableDb = dbHelper.readableDatabase
        writableDb = dbHelper.writableDatabase

        val activity = intent.getParcelableExtra("activity") as Activity?
        val pos = intent.getIntExtra("position", 0)
        if( pos !=0 )
            this.position = pos
        init_inputs(activity)


        button_save_edit.setOnClickListener{v: View ->
            edit_activity(v)
        }

        button_cancel_edit.setOnClickListener{
            intent = Intent()
            finish()
        }
    }

    private fun init_inputs(activity: Activity?) {

        if( activity != null){
            findViewById<EditText>(R.id.editText_titleActivity).setText(activity.title)
            findViewById<EditText>(R.id.editText_completeType).setText(activity.type)
            findViewById<EditText>(R.id.editText_completeDate).setText(activity.date)
            findViewById<EditText>(R.id.editText_completeStarTime).setText(activity.start_time)
            findViewById<EditText>(R.id.editText_completeDuration).setText(activity.duration)
            findViewById<EditText>(R.id.editText_completeIntensity).setText(activity.intensity)
            findViewById<EditText>(R.id.editText_completeDistance).setText(activity.distance)
            findViewById<EditText>(R.id.editText_completeDescription).setText(activity.description)

        }

    }

    fun edit_activity(view: View) {
        var correct = true
        val titleText = findViewById<EditText>(R.id.editText_titleActivity).text.toString()
        val typeText = findViewById<EditText>(R.id.editText_completeType).text.toString()
        val dateText = findViewById<EditText>(R.id.editText_completeDate).text.toString()
        val startTimeText = findViewById<EditText>(R.id.editText_completeStarTime).text.toString()
        val durationText = findViewById<EditText>(R.id.editText_completeDuration).text.toString()
        val intensityText = findViewById<EditText>(R.id.editText_completeIntensity).text.toString()
        val distanceText = findViewById<EditText>(R.id.editText_completeDistance).text.toString()
        val descriptionText = findViewById<EditText>(R.id.editText_completeDescription).text.toString()

        if (titleText == "") {
            Toast.makeText(this,"You must add title!", Toast.LENGTH_LONG).show()
            correct = false
        }
        if (typeText == "") {
            Toast.makeText(this,"You must add a type!", Toast.LENGTH_LONG).show()
            correct = false
        }
        if (dateText == ""){
            Toast.makeText(this,"You must add a date!", Toast.LENGTH_LONG).show()
            correct = false
        }
        if (startTimeText == "") {
            Toast.makeText(this,"You must add a start time!", Toast.LENGTH_LONG).show()
            correct = false
        }
        if (durationText == "") {
            Toast.makeText(this,"You must add duration!", Toast.LENGTH_LONG).show()
            correct = false
        }
        if (intensityText == ""){
            Toast.makeText(this,"You must add intensity!", Toast.LENGTH_LONG).show()
            correct = false
        }


        val editedActivity = Activity(position, titleText, typeText, dateText, startTimeText, durationText, intensityText, distanceText, descriptionText)

        if(correct){

            if (isNetworkConnected()) {
                ActivityAPI.retrofitService.updateActivity(position.toString(), editedActivity).enqueue(object :
                    Callback<Activity> {
                    override fun onFailure(call: Call<Activity>, t: Throwable) {
                        Log.d("TAG_TAG", "Failed :" + t.message)
                    }
                    override fun onResponse(call: Call<Activity>, response: Response<Activity>) {
                        Log.d("TAG_TAG", "Success :" + response.body())

                    }
                })
                DbRepository.getInstance(readableDb, writableDb)?.update(editedActivity)
            } else {
                showDialog()
//                DbRepository.getInstance(readableDb, writableDb)?.update(editedActivity)
            }

            val intent = Intent()
            intent.putExtra("activity", editedActivity)
            intent.putExtra("position", position)
            setResult(android.app.Activity.RESULT_OK, intent)
            finish()
        }
    }

    private fun showDialog(){
        AlertDialog.Builder(this).setTitle("No Internet Connection")
            .setMessage("Cannot EDIT!")
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