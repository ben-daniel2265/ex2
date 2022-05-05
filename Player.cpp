#ifndef HW2_PLAYER_source
#define HW2_PLAYER_source

#include "Player.h"
#include <string.h>

#define BASE_HP 100
#define BASE_ATTACK 5

char* copyString(const char* originalString)
{
    int size = strlen(originalString);
    char* string = new char[size + 1];

    strncpy(string, originalString, size);
    string[size] = '\0';

    return string;
}

Player::Player(const char* name)
{
    this->name = copyString(name);
    this->level = 1;
    this->force = BASE_ATTACK;
    this->maxHP = BASE_HP;
    this->HP = BASE_HP;
    this->coins = 0;
}

Player::Player(const char* name, int baseMaxHP)
{
    this->name = copyString(name);
    this->level = 1;
    this->force = BASE_ATTACK;
    this->maxHP = baseMaxHP;
    this->HP = baseMaxHP;
    this->coins = 0;
}

Player::Player(const char* name, int baseMaxHP, int baseForce)
{
    this->name = copyString(name);
    this->level = 1;
    this->force = baseForce;
    this->maxHP = baseMaxHP;
    this->HP = baseMaxHP;
    this->coins = 0;
}

Player::Player(const Player& player)
{
    this->name = player.name;
    this->level = player.level;
    this->force = player.force;
    this->maxHP = player.maxHP;
    this->HP = player.HP;
    this->coins = player.coins;
}

Player::~Player()
{
    delete[] name;
}

Player& Player::operator=(const Player& player)
{
    if(this == &player){
        return *this;
    }

    delete[] this->name;
    this->name = copyString(player.name);
    this->level = player.level;
    this->force = player.force;
    this->maxHP = player.maxHP;
    this->HP = player.HP;
    this->coins = player.coins;
}



void Player::printInfo()
{

}

void Player::levelUp()
{

}

int Player::getLevel()
{

}

void Player::buff(int amount)
{

}

void Player::heal(int amount)
{

}

void Player::damage(int amount)
{

}

bool Player::isKnockedOut()
{

}

void Player::addCoins(int amount)
{

}

bool Player::pay(int amount)
{

}

int Player::getAttackStrength()
{

}


#endif // HW2_PLAYER_source