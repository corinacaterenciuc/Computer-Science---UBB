package ro.korina.physicalactivity.db

import android.content.Context
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper


class Utils(context: Context?) :
    SQLiteOpenHelper(
        context,
        DATABASE_NAME,
        null,
        DATABASE_VERSION
    ) {
    override fun onCreate(db: SQLiteDatabase) {
        db.execSQL(SQL_CREATE_ENTRIES)
    }

    override fun onUpgrade(
        db: SQLiteDatabase,
        oldVersion: Int,
        newVersion: Int
    ) {
        // This database is only a cache for online data, so its upgrade policy is
        // to simply to discard the data and start over
        db.execSQL(SQL_DELETE_ENTRIES)
        onCreate(db)
    }

    override fun onDowngrade(
        db: SQLiteDatabase,
        oldVersion: Int,
        newVersion: Int
    ) {
        onUpgrade(db, oldVersion, newVersion)
    }

    companion object {
        // If you change the database schema, you must increment the database version.
        const val DATABASE_VERSION = 1
        const val DATABASE_NAME = "PhysicalActivity.db"
        private const val SQL_CREATE_ENTRIES =
            "CREATE TABLE " + Contract.FeedEntry.TABLE_NAME + " (" +
                    Contract.FeedEntry.COLUMN_NAME_ID + " INTEGER PRIMARY KEY ," +
                    Contract.FeedEntry.COLUMN_NAME_Title + " TEXT," +
                    Contract.FeedEntry.COLUMN_NAME_Type + " TEXT," +
                    Contract.FeedEntry.COLUMN_NAME_Date + " TEXT," +
                    Contract.FeedEntry.COLUMN_NAME_StartTime + " TEXT," +
                    Contract.FeedEntry.COLUMN_NAME_Duration + " TEXT," +
                    Contract.FeedEntry.COLUMN_NAME_Intensity + " TEXT," +
                    Contract.FeedEntry.COLUMN_NAME_Distance + " TEXT," +
                    Contract.FeedEntry.COLUMN_NAME_Description + " TEXT)"
        private const val SQL_DELETE_ENTRIES =
            "DROP TABLE IF EXISTS " + Contract.FeedEntry.TABLE_NAME
    }
}