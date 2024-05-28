#pragma once

#ifndef __MAGE_H__
#define __MAGE_H__

#include <iostream>

#include "Player.h"

class Mage: public virtual Player
{

public:
    Mage(const char* setName, const char* setAbility);
    virtual ~Mage();

public:
    virtual const bool attack (Player& other) const override;
    virtual void print (std::ostream& out = std::cout) override;

    void weaken (const Player* player, const float coefficient) const;

private:
    Mage(); // Cannot create mage without parameters

    virtual const unsigned int getMaxHealth () const override
    {
        return DEFAULT_HP;
    }

private:
   const char* specialAbility;

   static const int DEFAULT_HP = 80;
   static const int DEFAULT_DMG = 10;

}; 

#endif // __MAGE_H__