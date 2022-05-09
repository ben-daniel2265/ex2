#ifndef HW2_PLAYER_source
#define HW2_PLAYER_source

#include "Player.h"
#include "utilities.h"
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
    this->name = copyString(player.name);
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

    return *this;
}


void Player::printInfo() const
{
    printPlayerInfo(this->name,
                    this->level,
                    this->force,
                    this->HP,
                    this->coins);
}

void Player::levelUp()
{
    if(level < 10){
        level++;
    }
}

int Player::getLevel() const
{
    return level;
}

void Player::buff(int buffAmount)
{
    if(buffAmount > 0){
        this->force += buffAmount;
    }
}

void Player::heal(int healAmount)
{
    if(healAmount > 0){
        this->HP += healAmount;
        if(this->HP > this->maxHP){
            this->HP = this->maxHP;
        }
    }
}

void Player::damage(int damageAmount)
{
    if(damageAmount > 0){
        this->HP -= damageAmount;
        if(this->HP < 0){
            this->HP = 0;
        }
    }
}

bool Player::isKnockedOut() const
{
 return !this->HP;
}

void Player::addCoins(int coinAmount)
{
    if(coinAmount > 0){
        this->coins += coinAmount;
    }
}

bool Player::pay(int coinAmount)
{
    if(coinAmount >= this->coins){
        this->coins -= coinAmount;
        return true;
    }
    else{
        return false;
    }
}

int Player::getAttackStrength() const
{
    return this->force + this->level;
}


#endif // HW2_PLAYER_source