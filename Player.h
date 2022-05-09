#ifndef HW2_PLAYER
#define HW2_PLAYER

#include <stdio.h>
#include <stdbool.h>

#define BASE_HP 100
#define BASE_ATTACK 5

class Player{
    char* m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

    public:
    /*
    *  Constractor 1:
    *  only name given
    */
    Player(const char* name, int baseMaxHP = BASE_HP, int baseForce = BASE_ATTACK);
    Player(const Player& player);
    ~Player();
    Player& operator=(const Player& player);

    void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int buffAmount);
    void heal(int healAmount);
    void damage(int damageAmount);
    bool isKnockedOut() const;
    void addCoins(int coinAmount);
    bool pay(int coinAmount);
    int getAttackStrength() const;
};

#endif // HW2_PLAYER