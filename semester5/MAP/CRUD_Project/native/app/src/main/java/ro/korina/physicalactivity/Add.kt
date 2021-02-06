package ro.korina.physicalactivity

import android.app.AlertDialog
import android.content.Context
import android.content.Intent
import android.database.sqlite.SQLiteDatabase
import android.net.ConnectivityManager
import android.net.Network
import android.net.NetworkCapabilities
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.EditText
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_add.*
import org.jetbrains.anko.custom.onUiThread
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import ro.korina.physicalactivity.client.ActivityAPI
import ro.korina.physicalactivity.db.Utils
import ro.korina.physicalactivity.domain.Activity
import ro.korina.physicalactivity.domain.DbRepository
import ro.korina.physicalactivity.domain.MockData

class Add : AppCompatActivity() {

    private lateinit var readableDb: SQLiteDatabase
    private lateinit var writableDb: SQLiteDatabase

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_add)

        val dbHelper = Utils(this)
        readableDb = dbHelper.readableDatabase
        writableDb = dbHelper.writableDatabase


        button_save_add.setOnClickListener{v: View ->
            add_activity(v)
        }

        button_cancel_add.setOnClickListener{v: View ->
            val intent = Intent()
            setResult(android.app.Activity.RESULT_CANCELED, intent)
            finish()
        }
    }

    private fun add_activity(v: View) {
        var correct = true
        val titleText = findViewById<EditText>(R.id.editText_titleActivity).text.toString()
        val typeText = findViewById<EditText>(R.id.editText_type).text.toString()
        val dateText = findViewById<EditText>(R.id.editText_date).text.toString()
        val startTimeText = findViewById<EditText>(R.id.editText_startTime).text.toString()
        val durationText = findViewById<EditText>(R.id.editText_duration).text.toString()
        val intensityText = findViewById<EditText>(R.id.editText_intensity).text.toString()
        val distanceText = findViewById<EditText>(R.id.editText_distance).text.toString()
        val descriptionText = findViewById<EditText>(R.id.editText_description).text.toString()

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


        val addedActivity = Activity(null, titleText, typeText, dateText, startTimeText, durationText, intensityText, distanceText, descriptionText)

        if(correct){

            if (isNetworkConnected()) {
                ActivityAPI.retrofitService.createActivity(addedActivity).enqueue(object :
                    Callback<Activity> {
                    override fun onFailure(call: Call<Activity>, t: Throwable) {
                        Log.d("TAG_TAG", "Failed :" + t.message)
                        onUiThread {
                            val intent = Intent()
                            setResult(android.app.Activity.RESULT_OK, intent)
                            finish()
                        }
                    }
                    override fun onResponse(call: Call<Activity>, response: Response<Activity>) {
                        Log.d("TAG_TAG", "Success :" + response.body())
                    }
                })
                DbRepository.getInstance(readableDb, writableDb)?.add(addedActivity)
            } else {
                showDialog()
                DbRepository.getInstance(readableDb, writableDb)?.add(addedActivity)
                val intent = Intent()
                setResult(android.app.Activity.RESULT_OK, intent)
                finish()
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