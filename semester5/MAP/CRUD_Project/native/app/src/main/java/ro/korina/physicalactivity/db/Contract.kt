package ro.korina.physicalactivity.db

import android.provider.BaseColumns
/*
     val id: Int?,
    val title: String,
    val type: String,
    val date: String,
    val start_time: String = "",
    val duration: String = "",
    val intensity: String = "",
    val distance: String = "-",
    val description: String = ""
 */


class Contract
private constructor() {
    /* Inner class that defines the table contents */
    object FeedEntry : BaseColumns {
        const val TABLE_NAME = "Activity"
        const val COLUMN_NAME_ID = "id"
        const val COLUMN_NAME_Title = "title"
        const val COLUMN_NAME_Type = "type"
        const val COLUMN_NAME_Date = "date"
        const val COLUMN_NAME_StartTime = "startTime"
        const val COLUMN_NAME_Duration = "duration"
        const val COLUMN_NAME_Intensity = "intensity"
        const val COLUMN_NAME_Distance = "distance"
        const val COLUMN_NAME_Description = "description"
    }
}