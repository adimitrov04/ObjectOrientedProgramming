#pragma once

#ifndef __PLAYER_COLLECTION_H__
#define __PLAYER_COLLECTION_H__

#include "Player.h"

class PlayerCollection
{

public:
    PlayerCollection()
    : fcapacity(0),
      fsize(0),
      arr(nullptr)
    {}

    PlayerCollection(const PlayerCollection& other) = delete;
    PlayerCollection& operator= (const PlayerCollection& other) = delete;

    ~PlayerCollection()
    {
        clear();
    }

public:
    const size_t player_count () const;
    const size_t capacity () const;
    Player* at (const size_t index) const;

    void push_back (Player* player);
    void pop_back ();
    void reserve (const size_t cap);

    void clear ();

private:
    //void copy(const PlayerCollection& other);

private:
    size_t fcapacity;
    size_t fsize;
    Player** arr;

    static const size_t DEFAULT_CAPACITY = 4;

};

#endif // __PLAYER_COLLECTION_H__