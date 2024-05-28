#pragma once

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <stdexcept>

#include "Coordinate.h"
#include "Weapon.h"

enum PlayerType
{
    tWarrior,
    tMage,
    tNecromancer
};

class Player
{

public:
    Player ()
    : playerName(nullptr), healthPoints(0), attackDamage(0), currentPosition(0, 0)
    {}

    Player (const char* setName)
    : Player()
    {
        if (!setName)
            throw std::invalid_argument("Name cannot be nullptr.");

        playerName = setName;
    }

    virtual ~Player ()
    {
        delete[] playerName;
    }

public:
    const int get_HP () const
    {
        return healthPoints; 
    }

    unsigned int get_attack_damage () const
    {
        return attackDamage;
    }

    const bool is_alive () const
    {
        return (healthPoints > 0) ? true : false;
    }

    void move (const Coordinate& newPos)
    {
        currentPosition.x = newPos.x;
        currentPosition.y = newPos.y;
    }

    // GCC not letting me define pure virtual
    virtual const bool attack (Player& other) const
    {
        // No time to implement
        /*
        if (getDistanceTo(other) >= MIN_ATTACK_DIST)
            return false;
        */
    }

    virtual void handle_attack (const int dmgTaken)
    {
        healthPoints -= dmgTaken;
    }

    virtual void print (std::ostream& out = std::cout)
    {
        out << "Player name: " << playerName << '\n';
        out << "Class: " << getTypeString(type) << '\n';
        out << "Health: " << healthPoints << '/' << getMaxHealth() << '\n';
        out << "Position: " << currentPosition.x << ", " << currentPosition.y << "\n\n";
        
        out << "Weapon: " << getWeaponString(weapon) << '\n';
        out << "Attack: " << attackDamage << '\n';
    }

protected:
    virtual const unsigned int getMaxHealth () const = 0;

protected:
    const char* playerName;
    int healthPoints;
    unsigned int attackDamage;
    Coordinate currentPosition;
    Weapon weapon;
    PlayerType type;

    static const int MIN_ATTACK_DIST = 1;

private:
    static const char* getWeaponString (const Weapon type)
    {
        switch (type)
        {
        case Sword:
            return "Sword";
            break;
        
        case Wand:
            return "Wand";
            break;

        case Staff:
            return "Staff";
            break;

        case Axe:
            return "Axe";
            break;

        default:
            return "Unknown";
            break;
        }
    }

    static const char* getTypeString (const PlayerType type)
    {
        switch (type)
        {
        case tWarrior:
            return "Warrior";
            break;
        
        case tMage:
            return "Mage";
            break;

        case tNecromancer:
            return "Necromancer";
            break;

        default:
            return "Unknown";
            break;
        }
    }

};

#endif // __PLAYER_H__