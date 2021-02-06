package ro.korina.physicalactivity.client
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory

object ActivityAPI {
    private const val BASE_URL = " http://10.0.2.2:8080"
    private val retrofit = Retrofit.Builder()
        .addConverterFactory(GsonConverterFactory.create())
        .baseUrl(BASE_URL)
        .build()
    val retrofitService: ActivityService by lazy {
        retrofit.create(ActivityService::class.java)
    }
}