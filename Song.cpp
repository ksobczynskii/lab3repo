#include <string>
#include "SongDuration.hpp"
#include "Song.hpp"

Song::Song() : title{"Untitled"}, artist{"Unknown"}, duration{SongDuration()}
{
    count_songs++;
}
Song::Song(std::string tit, SongDuration dur, std::string art) : title{tit}, artist{art}, duration{SongDuration(0, dur.get_total_seconds())}
{
    count_songs++;
}
Song::Song(std::string tit, int min, int sec, std::string art)
{
    count_songs++;
    title = tit;
    artist = art;
    duration = SongDuration(min, sec);
}
Song &Song::operator=(const Song &other)
{
    if (this == &other)
    {
        return *this;
    }
    title = other.title;
    artist = other.artist;
    duration = SongDuration();
    return *this;
}
Song::~Song()
{
    count_songs--;
}
void Song::print()
{
    std::cout << title << ", Artist: " << artist << "[" << duration.get_formatted() << "]" << std::endl;
};
void Song::set_title(std::string t)
{
    title = t;
}
void Song::set_artist(std::string a)
{
    artist = a;
}
void Song::set_duration(int sec)
{
    duration = SongDuration(0, sec);
}
std::string Song::get_title()
{
    return title;
}
std::string Song::get_artist()
{
    return artist;
}
int Song::get_duration()
{
    return duration.get_total_seconds();
}

unsigned int Song::count_songs = 0;
int Song::get_total_songs()
{
    return Song::count_songs;
}
