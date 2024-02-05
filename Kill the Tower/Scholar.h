#ifndef SCHOLAR_H
#define SCHOLAR_H
#include "Character.h"

class Scholar : public Character{
public:
    Scholar();                                //default and overloaded constructors
    Scholar(string name);
    void calculateDamage(string);               //functions for damage, stats, setters and getters for stats
    void printStats();
    void resourceAbility();
    void incResource() {resource++;}
    int getAtkStat() {return atk;}
    int getEnergy() {return energy;}
    int getResource() {return resource;}
    int getMaxResource() {return maxResource;}
    int getMaxEnergy() {return maxEnergy;}
    void setMaxEnergy(int maxmana) {maxEnergy = maxmana;}
    void setAtkStat(int intel) {atk = intel;}
    void setEnergy(int mana) {this->energy = mana;}
    void setResource(int pwr) {resource = pwr;}
    void setMaxResource(int mpwr) {maxResource = mpwr;}
    void incEnergy(){                           //increase energy
        energy += 15;
        if(energy > maxEnergy){
            energy = maxEnergy;
        }
        cout << name << " regained 15 mana!" << endl;
    }
    int Explosion(int dmg);                           //attacks and menus, leveling up, and saving
    int Smite(int dmg);
    int Typhoon(int dmg);
    void Heal();
    void battleMenu();
    void spellMenu();
    void resourcespellMenu();
    void battleStats();
    void afterBattle();
    void save();
};
#endif
