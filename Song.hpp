#pragma once
#include <string>
#include "SongDuration.hpp"
class Song
{
private:
    std::string title;
    std::string artist;
    SongDuration duration;

public:
    Song();
    Song(std::string tit, SongDuration durs, std::string art = "Unknown");
    Song(std::string tit, int min = 0, int sec = 0, std::string art = "Unknown");
    Song &Song::operator=(const Song &other);
    void print();
    ~Song();
    void set_title(std::string);
    void set_artist(std::string);
    void set_duration(int sec);
    std::string get_title();
    std::string get_artist();
    int get_duration();
    static unsigned int count_songs;
    static int get_total_songs();
};
