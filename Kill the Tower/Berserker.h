#ifndef BERSERKER_H
#define BERSERKER_H

#include "Character.h"

class Berserker : public Character{
public:
    Berserker();                                //default and overloaded constructors
    Berserker(string name);
    void calculateDamage(string);               //functions for damage, stats, setters and getters for stats
    void printStats();
    void resourceAbility();
    void incResource() {resource++;}
    int getResource() {return resource;}
    int getMaxResource() {return maxResource;}
    int getAtkStat() {return atk;}
    int getEnergy() {return energy;}
    int getMaxEnergy() {return maxResource;}
    void setResource(int rage) {this->resource = rage;}
    void setMaxResource(int maxRage) {this->maxResource = maxRage;}
    void setAtkStat(int str) {this->atk = str;}
    void setEnergy(int stam) {this->energy = stam;}
    void setMaxEnergy(int stami) {maxEnergy = stami;}
    void incEnergy(){                           //increase energy
        energy += 15;
        if(energy > maxEnergy){
            energy = maxEnergy;
        }
        cout << name << " regained 15 stamina!" << endl;
    }
    int bashAtk(int);                           //attacks and menus, leveling up, and saving
    int slashAtk(int);
    int vampiricAtk(int);
    void battleMenu();
    void atkMenu();
    void battleStats();
    void afterBattle();
    void save();


};




#endif