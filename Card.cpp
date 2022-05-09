#ifndef EX2_Card_SOURCE
#define EX2_Card_SOURCE

#include "Card.h"
#include "utilities.h"
#include "Player.h"


Card::Card(CardType type, const CardStats& stats)
{
    this->m_effect = type;
    this->m_stats = CardStats(stats);
}


void Card::applyEncounter(Player& player) const
{
    if(this->m_effect == CardType::Battle){
        if(this->m_stats.force > player.getAttackStrength()){
            player.damage(this->m_stats.hpLossOnDefeat);
            printBattleResult(false);
        }
        else{
            player.addCoins(this->m_stats.loot);
            player.levelUp();
            printBattleResult(true);
        }
    }
    else if(this->m_effect == CardType::Heal){
        if(player.pay(this->m_stats.cost)){
            player.heal(this->m_stats.heal);
        }
    }
    else if(this->m_effect == CardType::Buff){
        if(player.pay(this->m_stats.cost)){
            player.buff(this->m_stats.buff);
        }
    }
    else if(this->m_effect == CardType::Treasure){
        player.addCoins(this->m_stats.loot);
    }
}


void Card::printInfo() const
{
    if(this->m_effect == CardType::Battle){
        printBattleCardInfo(this->m_stats);
    }
    else if(this->m_effect == CardType::Heal){
        printHealCardInfo(this->m_stats);
    }
    else if(this->m_effect == CardType::Buff){
        printBuffCardInfo(this->m_stats);
    }
    else if(this->m_effect == CardType::Treasure){
        printTreasureCardInfo(this->m_stats);
    }
}






#endif //EX2_Card_SOURCE