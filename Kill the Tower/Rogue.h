#ifndef ROGUE_H
#define ROGUE_H
#include "Character.h"

class Rogue : public Character{
public:
    Rogue();                                //default and overloaded constructors
    Rogue(string name);
    void calculateDamage(string);               //functions for damage, stats, setters and getters for stats
    void printStats();
    void resourceAbility();
    void incResource() {resource++;}
    int getResource() {return resource;}
    int getMaxResource() {return maxResource;}
    int getEnergy() {return energy;}
    int getAtkStat() {return atk;}
    int getMaxEnergy() {return maxEnergy;}
    void setMaxEnergy(int utili) {maxEnergy = utili;}
    void setResource(int s) {resource = s;}
    void setMaxResource(int ms) {maxResource = ms;}
    void setEnergy(int util) {energy = util;}
    void setAtkStat(int cun) {atk = cun;}
    void incEnergy(){                           //increase energy
        energy++;
        if(energy > maxEnergy){
            energy = maxEnergy;
        }
        cout << name << " regained 1 utility use!" << endl;
    }
    int Dagger(int); //bleed                                //attacks and menus, leveling up, and saving
    int Bolas(int); //vulnerable
    int smokeBomb(int); //dodge chance up
    void Potion();
    void Elixir();
    void battleMenu();
    void utilMenu();
    void battleStats();
    void afterBattle();
    void save();
    private:
        int dodgecap;                                       //dodgecap for rogue

};


#endif