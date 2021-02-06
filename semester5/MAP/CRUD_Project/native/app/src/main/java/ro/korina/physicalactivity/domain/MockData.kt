package ro.korina.physicalactivity.domain


class MockData {
    companion object {
        private var instance: MockData =
            MockData()

        fun getInstance(): MockData {
            return instance
        }
    }

    private var activities = mutableListOf<Activity>(
        Activity(
            null,
            "run 1 - Marathon Training",
            "run",
            "12.10.2019",
            "12:30",
            "43 mins",
            "medium",
            "5.5 km",
            "went too fast in the beginning"),

        Activity(
            null,
            "run 2 - Long run",
            "run",
            "12.10.2019",
            "12:30",
            "80 mins",
            "easy",
            "15 km",
            "idk what was this"),

        Activity(
            null,"plimbare de seara",
            "walk",
            "18.10.2019",
            "18:00",
            "30 min",
            "easy",
            "-",
            "waled with my thoughts"),

        Activity(
            null,"dance",
            "run",
            "23.11.2019",
            "20:11",
            "23 min",
            "medium",
            "-",
            "From Now On by The Greatest Showman"),

        Activity(
            null,"swim1",
            "swim",
            "10.08.2019",
            "12:30",
            "20 min",
            "hard",
            "0.5 km",
            "good swim"
        )
    )

    fun getElement(): MutableList<Activity> {
        return this.activities
    }
}