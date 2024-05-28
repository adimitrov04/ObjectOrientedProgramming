#include <cstddef>
#include <new>
#include <stdexcept>

#include "PlayerCollection.h"

const size_t PlayerCollection::player_count () const
{
    return fsize;
}

const size_t PlayerCollection::capacity () const
{
    return fcapacity;
}

Player* PlayerCollection::at (const size_t index) const
{
    if (index < 0 || index >= fsize)
        throw std::range_error("Given index does not exist.");

    return arr[index];
}

void PlayerCollection::push_back (Player* player)
{
    if (!player)
        throw std::invalid_argument("Cannot push nullptr.");
    
    if (fcapacity == 0)
        reserve(DEFAULT_CAPACITY);

    if (fsize == fcapacity)
    {
        reserve(fcapacity * 2);
    }

    arr[fsize] = player;
}

void PlayerCollection::pop_back ()
{
    if (fsize <= 0)
        return;

    delete arr[fsize - 1];
    arr[fsize - 1] = nullptr;

    fsize--;
}

void PlayerCollection::reserve (const size_t cap)
{
    if (cap <= fcapacity)
        return;

    Player** buffer = new Player*[cap];

    for (size_t i = 0; i < fsize; fsize++)
    {
        buffer[i] = arr[i];
    }

    delete[] arr;
    arr = buffer;
    fcapacity = cap;
}

void PlayerCollection::clear ()
{
    for (size_t i = 0; i < fsize; i++)
        delete arr[i];

    delete[] arr;
    arr = nullptr;

    fsize = 0;
    fcapacity = 0;
}