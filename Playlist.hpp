#pragma once
#include "Song.hpp"
class Playlist
{
private:
    Song *songs;
    unsigned int capacity;
    unsigned int size;
    void resize(unsigned int new_capacity);

public:
    Playlist(unsigned int init_cap = 10);
    Playlist(const Playlist &other);
    Playlist &operator=(const Playlist &other);
    Playlist(Playlist &&other);
    Playlist &operator=(Playlist &&other);
    ~Playlist();
    void add_song(const Song &song);
    int get_size();
    void print();
};