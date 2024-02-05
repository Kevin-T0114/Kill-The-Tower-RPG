#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy{
public:
    Enemy();                                    //default constructor, overloaded constructor, getters and setters for stats
    Enemy(string name) {this->name = name;}
    int getCurrHP() {return currHP;}
    void setCurrHP(int HP) {currHP = HP;}
    int getMaxHP() {return maxHP;}
    void setMaxHP(int HP) {maxHP = HP;}
    int getDef() {return def;}
    void setDef(int def) {this->def = def;}
    int getAtk() {return atk;}
    void setAtk(int atk) {this->atk = atk;}
    string getName() {return name;}
    void setName(string name) {this->name = name;}
    virtual void dmgCalc() {}                               //damage calculation functions, attacks, print stats
    virtual int Attack(int) {return 0;}
    virtual int Attack2(int) {return 0;}
    virtual int Special(int) {return 0;}
    void incSpecialPts() {specialPts++;}
    void stats();
    void Death(){                                            //deth widepeepohappy
        cout << name << " has been defeated!" << endl;
    }
    void applyPoison(){                                     //status effects
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
    void resetWeak() {weak = false;}
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
    int getDmg(){return dmg;}

protected:                                          //variables
    int currHP, maxHP, def, atk, dmg, specialPts;
    string name;
    bool poisoned = false;
    bool weak = false;
    bool vuln = false;
    bool applypoison = false;
    bool applyweak = false;
    bool applyvuln = false;

};

void Enemy::stats(){                                //stats definition
    cout << name << ": HP - " << currHP << "/" << maxHP << " ATK - " << atk << " DEF - " << def << endl;
}


#endif