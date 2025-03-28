#pragma once
#include <iostream>
#include <string>

class SongDuration
{
private:
    unsigned int minutes;
    unsigned int seconds;

public:
    SongDuration() : minutes{0}, seconds{0} {};
    SongDuration(unsigned int min, unsigned int sec)
    {
        min += sec / 60;
        minutes = min;
        sec = sec % 60;
        seconds = sec;
        // std::cout << "Minutes: " << minutes << "Seconds: " << seconds << std::endl;
    }
    unsigned int get_total_seconds()
    {
        return minutes * 60 + seconds;
    }
    std::string get_formatted()
    {
        std::string retVal = std::to_string(minutes) + "m" + std::to_string(seconds) + "s";
        return retVal;
    }
};