#include "Playlist.hpp"

Playlist::Playlist(unsigned int init_cap) : capacity{init_cap}, size{0}
{
    std::cout << "Penis" << std::endl;
    Song *songs = new Song[init_cap];
    std::cout << "Penis2" << std::endl;
}
Playlist::Playlist(const Playlist &other) : capacity{other.capacity}, size{other.size}, songs{other.songs} {};
Playlist &Playlist::operator=(const Playlist &other)
{
    if (this == &other)
    {
        return *this;
    }
    if (capacity != other.capacity)
    {
        delete[] this->songs;
        this->songs = new Song[other.capacity];
        this->capacity = other.capacity;
    }
    size = other.size;
    for (int i = 0; i < size; i++)
    {
        songs[i] = other.songs[i];
    }
    return *this;
}
Playlist::Playlist(Playlist &&other) : capacity{other.capacity}, size{other.size}, songs{other.songs}
{
    other.capacity = 0;
    other.size = 0;
    other.songs = nullptr;
}
Playlist &Playlist::operator=(Playlist &&other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] this->songs;
    capacity = other.capacity;
    size = other.size;
    songs = other.songs;
    other.capacity = 0;
    other.size = 0;
    other.songs = nullptr;
    return *this;
}
Playlist::~Playlist() {
};

void Playlist::resize(unsigned int new_capacity)
{
    this->capacity = new_capacity;
}
void Playlist::add_song(const Song &song)
{

    if (size == capacity)
    {
        this->resize(2 * capacity);
    }
    std::cout << "Penis7" << std::endl;
    songs[size++] = song;
    std::cout << "Penis8" << std::endl;
}
int Playlist::get_size()
{
    return size;
}
void Playlist::print()
{
    if (size == 0)
    {
        std::cout << "Playlist is empty" << std::endl;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ". ";
        songs[i].print();
    }
}
