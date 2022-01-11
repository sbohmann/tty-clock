# pragme once

struct RoundedTimestamp {
    int (*get_time) (struct timespec &result);
};

time_t RoundedTimestamp_get(struct RoundedTimestamp self) {
    static const long HALF_SECOND_IN_NANOSECONDS = 500 * 1000 * 1000;
    struct timespec currentTime;

    if (self.get_time(&currentTime) != 0)
    {
        return time(NULL);
    }

    if (currentTime.tv_nsec >= HALF_SECOND_IN_NANOSECONDS)
    {
        return currentTime.tv_sec + 1;
    }
    else
    {
        return currentTime.tv_sec;
    }
}
