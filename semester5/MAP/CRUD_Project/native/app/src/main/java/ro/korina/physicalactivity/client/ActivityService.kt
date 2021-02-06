package ro.korina.physicalactivity.client
import retrofit2.Call
import retrofit2.http.*
import ro.korina.physicalactivity.domain.Activity

interface ActivityService {
    @GET("/activities/{id}")
    fun retrieveActivity(@Path("id") id: String) : Call<Activity>
    @GET("/activities")
    fun retrieveAllActivities() : Call<List<Activity>>
    @DELETE("/activities/{id}")
    fun deleteActivity(@Path("id") id: String) : Call<Activity>
    @POST("/activities")
    fun createActivity(@Body activity: Activity) : Call<Activity>
    @PUT("/activities/{id}")
    fun updateActivity(@Path("id") id: String, @Body activity: Activity) : Call<Activity>
}