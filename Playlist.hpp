#pragma once
#include "Song.hpp"
class Playlist
{
private:
    Song *songs;
    unsigned int capacity;
    unsigned int size;

public:
    Playlist(unsigned int init_cap = 10) : songs{}, capacity{init_cap}, size{0} {};
    Playlist(const Playlist &other) : capacity{other.capacity}, size{other.size}, songs{other.songs} {};
    Playlist &operator=(const Playlist &other);
    Playlist(Playlist &&other);
    Playlist &operator=(Playlist &&other);
    ~Playlist();
};