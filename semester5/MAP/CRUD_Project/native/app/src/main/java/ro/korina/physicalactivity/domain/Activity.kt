package ro.korina.physicalactivity.domain

import android.os.Parcelable
import com.google.gson.annotations.SerializedName
import kotlinx.android.parcel.Parcelize

@Parcelize
data class Activity (
    @SerializedName("id")
    val id: Int?,
    @SerializedName("title")
    val title: String,
    @SerializedName("type")
    val type: String,
    @SerializedName("date")
    val date: String,
    @SerializedName("startTime")
    val start_time: String = "",
    @SerializedName("duration")
    val duration: String = "",
    @SerializedName("intensity")
    val intensity: String = "",
    @SerializedName("distance")
    val distance: String = "-",
    @SerializedName("description")
    val description: String = ""
) :Parcelable