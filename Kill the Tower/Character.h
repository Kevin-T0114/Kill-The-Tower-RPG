#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>                 //include needed libraries
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <stdexcept>



using namespace std;

class Not123Error {};
class InvalidActionError {};                        //declare exception error classes

class Character{
public:
    Character() {name = "default";}                     //default and overloaded constructors
    Character(string name) {this->name = name;}          //getters and setters for stat values
    string getName() {return name;}
    int getDodge(){return dodge;}
    void setName(string name) {this->name = name;}
    int getCurrHP() {return currHP;}
    void setCurrHP(int HP) {currHP = HP;}
    int getMaxHP() {return maxHP;}
    void setMaxHP(int HP) {maxHP = HP;}
    int getDefense() {return def;}
    void setDefense(int def) {this->def = def;}
    int getFloor() {return floor;}
    void setFloor(int floor) {this->floor = floor;}
    void incResource(){resource++;}                 //increment special ability point
    int getDmg() {return dmg;}
    virtual int getAtkStat() {return 0;}
    virtual void setAtkStat(int){}
    virtual int getEnergy(){return 0;}
    virtual void setEnergy(int){}
    virtual int getMaxEnergy(){return 0;}
    virtual void setMaxEnergy(int){}
    virtual int getResource(){return 0;}
    virtual void setResource(int){}
    virtual int getMaxResource(){return 0;}
    virtual void setMaxResource(int){}
    virtual void calculateDamage(string atkType){}
    virtual void printStats(){}
    virtual void save(){}
    virtual void resourceAbility(){}
    virtual void battleMenu(){}
    virtual void battleStats(){}
    virtual void afterBattle(){}
    virtual void incEnergy(){}
    void Death(){                                     //deth widepeepohappy
        srand(time(0));
        int random = rand() % 101;
        if (random <= 50){
            cout << "You suck, click this link for a tutorial! -> https://www.youtube.com/watch?v=xm3YgoEiEDc" << endl;
        }
        else{
            cout << name << " has been slain on floor " << floor << endl;
        }
    }
    void applyPoison(){                                //status effects
        applypoison = true;
    }
    void applyWeak(){
        applyweak = true;
    }
    void applyVuln(){
        applyvuln = true;
    }
    void resetapplyPoison(){
        applypoison = false;
    }
    void resetapplyWeak(){
        applyweak = false;
    }
    void resetapplyVuln(){
        applyvuln = false;
    }
    bool isPoison(){
        return poisoned;
    }
    bool isWeak(){
        return weak;
    }
    bool isVuln(){
        return vuln;
    }
    void Poison(){
        if(isPoison()){
            currHP -= ceil(maxHP*.05);
            cout << name << " took " << ceil(maxHP*.05) << " damage from poison!" << endl;
        }
    }
    void Weak(){
        if(isWeak()){
            dmg = ceil(dmg*.85);
        }
    }
    void setPoisoned(){
        poisoned = true;
    }
    void setWeak(){
        weak = true;
    }
    void resetWeak(){
        weak = false;
    }
    void setVuln(){
        vuln = true;
    }
    bool getApplyPoison(){
        return applypoison;
    }
    bool getApplyWeak(){
        return applyweak;
    }
    bool getApplyVuln(){
        return applyvuln;
    }
    string Lowercase(string word){                          //changes input to lowercase
        string newWord = "";
        for (int i = 0; i < word.size(); i++){
            newWord += tolower(word.at(i));
        }
        return newWord;
}
protected:                                                  //protected variables for children class
    string name;
    int currHP, maxHP, dmg, def, dodge, floor, atk, energy, maxEnergy, resource, maxResource;
    bool weak = false;
    bool poisoned = false;
    bool vuln = false;
    bool applypoison = false;
    bool applyweak = false;
    bool applyvuln = false;

};


#endif 