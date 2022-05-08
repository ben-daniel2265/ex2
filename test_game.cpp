#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Player.h"

using namespace std;


int main(){
    Player p1 = Player("Daniel", 200, 10);
    p1.printInfo();
    p1.buff(5);

    Player p2 = Player(p1);
    p2.damage(50);
    p2.heal(100);
    p2.printInfo();

    Player p3 = Player("Elbaz");

    p3 = p1;

    p3.levelUp();
    p3.addCoins(20);
    p3.printInfo();

    cout << p3.isKnockedOut();
    p3.damage(300);
    cout << p3.isKnockedOut();


    return 0;
}