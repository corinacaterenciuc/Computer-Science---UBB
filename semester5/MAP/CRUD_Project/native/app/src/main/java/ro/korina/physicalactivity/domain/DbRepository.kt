package ro.korina.physicalactivity.domain

import android.content.ContentValues
import android.database.sqlite.SQLiteDatabase
import ro.korina.physicalactivity.db.Contract

import java.util.*
import kotlin.collections.ArrayList

class DbRepository private constructor(
    private var readableDatabase: SQLiteDatabase,
    private var writableDatabase: SQLiteDatabase
) {
    private var repository: MutableList<Activity> = ArrayList()

    fun getAllTitles() : MutableList<String>{
        val data: MutableList<Activity> = ArrayList()
        val cursor = readableDatabase.query(
            Contract.FeedEntry.TABLE_NAME,
            null,
            null,
            null,
            null,
            null,
            null
        )
        while (cursor.moveToNext()) {
            val id = cursor.getInt(cursor.getColumnIndexOrThrow("id"))
            val title = cursor.getString(cursor.getColumnIndexOrThrow("title"))
            val type = cursor.getString(cursor.getColumnIndexOrThrow("type"))
            val date = cursor.getString(cursor.getColumnIndexOrThrow("date"))
            val startTime = cursor.getString(cursor.getColumnIndexOrThrow("startTime"))
            val duration = cursor.getString(cursor.getColumnIndexOrThrow("duration"))
            val intensity = cursor.getString(cursor.getColumnIndexOrThrow("intensity"))
            val distance = cursor.getString(cursor.getColumnIndexOrThrow("distance"))
            val description = cursor.getString(cursor.getColumnIndexOrThrow("description"))
            val activity = Activity(id, title, type, date, startTime, duration, intensity, distance, description)
            data.add(activity)
        }
        cursor.close()
        val activities: ArrayList<String> =  ArrayList()
        for (e in data){
            activities.add(e.title)
        }
        repository = data
        return activities.toMutableList()
    }

    fun getAll(): MutableList<Activity> {
        val data: MutableList<Activity> = ArrayList()
        val cursor = readableDatabase.query(
            Contract.FeedEntry.TABLE_NAME,
            null,
            null,
            null,
            null,
            null,
            null
        )
        while (cursor.moveToNext()) {
            val id = cursor.getInt(cursor.getColumnIndexOrThrow("id"))
            val title = cursor.getString(cursor.getColumnIndexOrThrow("title"))
            val type = cursor.getString(cursor.getColumnIndexOrThrow("type"))
            val date = cursor.getString(cursor.getColumnIndexOrThrow("date"))
            val startTime = cursor.getString(cursor.getColumnIndexOrThrow("startTime"))
            val duration = cursor.getString(cursor.getColumnIndexOrThrow("duration"))
            val intensity = cursor.getString(cursor.getColumnIndexOrThrow("intensity"))
            val distance = cursor.getString(cursor.getColumnIndexOrThrow("distance"))
            val description = cursor.getString(cursor.getColumnIndexOrThrow("description"))
            val activity = Activity(id, title, type, date, startTime, duration, intensity, distance, description)
            data.add(activity)
        }
        cursor.close()
        repository = data
        return repository.toMutableList()
    }

    fun add(activity: Activity): Boolean {
        val values = ContentValues()
        values.put(Contract.FeedEntry.COLUMN_NAME_ID, activity.id)
        values.put(Contract.FeedEntry.COLUMN_NAME_Title, activity.title)
        values.put(Contract.FeedEntry.COLUMN_NAME_Type, activity.type)
        values.put(Contract.FeedEntry.COLUMN_NAME_Date, activity.date)
        values.put(Contract.FeedEntry.COLUMN_NAME_StartTime, activity.start_time)
        values.put(Contract.FeedEntry.COLUMN_NAME_Duration, activity.duration)
        values.put(Contract.FeedEntry.COLUMN_NAME_Intensity, activity.intensity)
        values.put(Contract.FeedEntry.COLUMN_NAME_Distance, activity.distance)
        values.put(Contract.FeedEntry.COLUMN_NAME_Description, activity.description)
        writableDatabase.insert(Contract.FeedEntry.TABLE_NAME, null, values)
        return true
    }

    fun delete(id: String): Boolean {
        val selection: String = Contract.FeedEntry.COLUMN_NAME_ID + " LIKE ?"
        val selectionArgs =
            arrayOf(id)
        writableDatabase.delete(Contract.FeedEntry.TABLE_NAME, selection, selectionArgs)
        return true
    }

    fun getById(id: Int): Activity? {
        for (i in repository.indices) {
            if (id == repository[i].id) {
                return repository[i]
            }
        }
        return null
    }

    fun update(activity: Activity): Activity? {
        val values = ContentValues()
        values.put(Contract.FeedEntry.COLUMN_NAME_ID, activity.id)
        values.put(Contract.FeedEntry.COLUMN_NAME_Title, activity.title)
        values.put(Contract.FeedEntry.COLUMN_NAME_Type, activity.type)
        values.put(Contract.FeedEntry.COLUMN_NAME_Date, activity.date)
        values.put(Contract.FeedEntry.COLUMN_NAME_StartTime, activity.start_time)
        values.put(Contract.FeedEntry.COLUMN_NAME_Duration, activity.duration)
        values.put(Contract.FeedEntry.COLUMN_NAME_Intensity, activity.intensity)
        values.put(Contract.FeedEntry.COLUMN_NAME_Distance, activity.distance)
        values.put(Contract.FeedEntry.COLUMN_NAME_Description, activity.description)
        val selection: String = Contract.FeedEntry.COLUMN_NAME_ID + " LIKE ?"
        val selectionArgs = arrayOf(activity.id.toString())
        writableDatabase.update(Contract.FeedEntry.TABLE_NAME, values, selection, selectionArgs)
        return null
    }

    fun getPartialElements(pattern :String): ArrayList<String> {
        val toBeReturned = ArrayList<String>()
        for (element in this.repository) {
            toBeReturned.add(element.title)
        }
        val it: MutableIterator<String> = toBeReturned.iterator()
        while (it.hasNext()) {
            if (!it.next().toLowerCase(Locale.ROOT)
                    .contains(pattern.toLowerCase(Locale.ROOT))
            )
                it.remove()
        }
        return toBeReturned
    }

    companion object {
        private var instance: DbRepository? = null
        fun getInstance(rdb: SQLiteDatabase, wdb: SQLiteDatabase): DbRepository? {
            if (instance == null) instance = DbRepository(rdb, wdb)
            return instance
        }
    }
}