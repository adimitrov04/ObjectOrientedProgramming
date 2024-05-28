#include <iostream>
#include <stdexcept>
#include <ctime>

#include "Mage.h"

Mage::Mage(const char* setName, const char* setAbility)
: Player(setName)
{
    if (!setAbility)
        throw std::invalid_argument("Mage ability cannot be nullptr.");

    this->type = PlayerType::tMage;
    this->weapon = Weapon::Wand;

    healthPoints = DEFAULT_HP;
    attackDamage = DEFAULT_DMG;

    specialAbility = setAbility;
}

Mage::~Mage()
{
    delete[] specialAbility;
}

const bool Mage::attack (Player& player) const
{
    Player::attack(player);
    float weakenCoefficient = 0.2f; // This is supposed to be random, but dont know how to generate
    
    const int dealDamage = (player.get_HP() * weakenCoefficient) + attackDamage;
    player.handle_attack(dealDamage);
}

void Mage::print (std::ostream& out)
{
    Player::print(out);
    out << "Special ability: " << specialAbility << '\n';
}
