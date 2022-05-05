#ifndef HW2_PLAYER
#define HW2_PLAYER

#include <stdio.h>
#include <stdbool.h>

class Player{
    char* name;
    int level;
    int force;
    int maxHP;
    int HP;
    int coins;

    public:
    /*
    *  Constractor 1:
    *  only name given
    */
    Player(const char* name);
    Player(const char* name, int maxHP);
    Player(const char* name, int baseMaxHP, int baseForce);
    Player(const Player&);
    ~Player();

    Player& operator=(const Player& player);    
    void printInfo();
    void levelUp();
    int getLevel();
    void buff(int amount);
    void heal(int amount);
    void damage(int amount);
    bool isKnockedOut();
    void addCoins(int amount);
    bool pay(int amount);
    int getAttackStrength();
};

#endif // HW2_PLAYER