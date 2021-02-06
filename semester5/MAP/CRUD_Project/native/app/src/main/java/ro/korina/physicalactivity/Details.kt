package ro.korina.physicalactivity

import android.app.AlertDialog
import android.app.Dialog
import android.content.Context
import android.content.Intent
import android.database.sqlite.SQLiteDatabase
import android.net.ConnectivityManager
import android.net.NetworkCapabilities
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.TextView
import kotlinx.android.synthetic.main.activity_details.*
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import ro.korina.physicalactivity.client.ActivityAPI
import ro.korina.physicalactivity.db.Utils
import ro.korina.physicalactivity.domain.Activity
import ro.korina.physicalactivity.domain.DbRepository

class Details  : AppCompatActivity() {
    private var position: Int = 0
    private lateinit var readableDb: SQLiteDatabase
    private lateinit var writableDb: SQLiteDatabase

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_details)

        val dbHelper = Utils(this)
        readableDb = dbHelper.readableDatabase
        writableDb = dbHelper.writableDatabase


        val activity = intent.getParcelableExtra("activity") as Activity?
        val pos = intent.getIntExtra("position", 0)
        if( pos !=0 )
            this.position = pos
        show_details(activity)

        button_back_detail.setOnClickListener{ v: View ->
            val intent = Intent()
            setResult(android.app.Activity.RESULT_OK, intent)
            finish()
        }

        button_edit_detail.setOnClickListener { v: View ->
            val intent = Intent(v.context, Edit::class.java)
            intent.putExtra("activity", activity)
            intent.putExtra("position", position)
            startActivityForResult(intent, 3)
            finish()
        }

        button_delete_detail.setOnClickListener{v: View ->
            val dialog = Dialog(v.context)
            dialog.setCancelable(true)
            dialog.setContentView(R.layout.delete_popup)
            val yes = dialog.findViewById<Button>(R.id.button_yesDelete) as Button
            yes.setOnClickListener{

                if (isNetworkConnected()) {
                    ActivityAPI.retrofitService.deleteActivity(position.toString()).enqueue(object :
                        Callback<Activity> {
                        override fun onFailure(call: Call<Activity>, t: Throwable) {
                            Log.d("TAG_TAG", "Failed :" + t.message)
                        }
                        override fun onResponse(call: Call<Activity>, response: Response<Activity>) {
                            Log.d("TAG_TAG", "Success :" + response.body())

                        }
                    })
                    DbRepository.getInstance(readableDb, writableDb)?.delete(position.toString())
                } else {
                    showDialog()
//                    DbRepository.getInstance(readableDb, writableDb)?.delete(position.toString())
                }

                val intent = Intent()
                setResult(android.app.Activity.RESULT_OK, intent)
                dialog.dismiss()
                finish()
            }
            val no = dialog.findViewById<Button>(R.id.button_cancelDelete) as Button
            no.setOnClickListener{
                dialog.dismiss()
            }

            dialog.show()
        }
    }

    private fun show_details(activity: Activity?)
    {
        if( activity != null)
        {
            print(activity.title)
            findViewById<TextView>(R.id.textView_titleActivity).text = activity.title
            findViewById<TextView>(R.id.textView_completeType).text = activity.type
            findViewById<TextView>(R.id.textView_completeDate).text = activity.date
            findViewById<TextView>(R.id.textView_completeStartTime).text = activity.start_time
            findViewById<TextView>(R.id.textView_completeDurantion).text = activity.duration
            findViewById<TextView>(R.id.textView_completeIntencity).text = activity.intensity
            findViewById<TextView>(R.id.textView_completeDistance).text = activity.distance
            findViewById<TextView>(R.id.textView_completeDescription).text = activity.description

        }
    }

    private fun showDialog(){
        AlertDialog.Builder(this).setTitle("No Internet Connection")
            .setMessage("Cannot DELETE!")
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