package ro.korina.physicalactivity.domain

import android.content.Context
import android.content.Intent
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import kotlinx.android.synthetic.main.item_activity.view.*
import ro.korina.physicalactivity.R
import ro.korina.physicalactivity.Details


class ActivityAdapter (val activities: MutableList<Activity>) : RecyclerView.Adapter<ActivityAdapter.ActivityViewHolder>()
{


    private var context: Context? = null
    private final var intent: Intent? = null

    inner class ActivityViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView),
        View.OnClickListener{

        init {
            context = itemView.context
            itemView.setOnClickListener(this)
        }

        override fun onClick(v: View?) {
            val context = v?.context
            val intent = Intent(context, Details::class.java)
            intent.putExtra("activity", activities[adapterPosition])
            intent.putExtra("position", activities[adapterPosition].id)
            (context as android.app.Activity).startActivityForResult(intent, 2)

        }

    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ActivityViewHolder {

        return ActivityViewHolder(
            LayoutInflater.from(parent.context).inflate(
                R.layout.item_activity,
                parent,
                false
            )
        )

    }

    override fun getItemCount(): Int {
        return activities.size
    }

    override fun onBindViewHolder(holder: ActivityViewHolder, position: Int) {
        var currentActivity = activities[position]
        holder.itemView.apply {
            textView_titleItemActivity.text = currentActivity.title
            textView_typeItemActivity.text = currentActivity.type
            textView_dateItemActivity.text = currentActivity.date
        }


    }
}