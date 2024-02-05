#include "Stonipede.h"
Stonipede::Stonipede() : Enemy("Stonipede"){                              //default constructor
//currHP maxHP, def, atk, dmg, specialPts;
    maxHP = 130;
    currHP = maxHP;
    def = 10;
    atk = 3;
    specialPts = 0;
}



Stonipede::Stonipede(int floor) : Enemy("Stonipede"){                     //overloaded constructor
    maxHP = ceil(130 * (1 + floor*0.15));
    currHP = maxHP;
    def = ceil(10 * (1 + floor*0.10));
    atk = ceil(3 * (1 + floor*0.10));
    specialPts = 0;

}

void Stonipede::dmgCalc(){                                            //damage calculations based on random attack
    dmg = atk;
    if(specialPts == 2){
        dmg = Special(dmg);
    }
    else{    
        srand(time(0));
        switch(rand() % 2){
            case(0):
                dmg = Attack(dmg);
                break;
            case(1):
                dmg = Attack2(dmg);
                break;
    }
    }

}
int Stonipede::Attack(int dmg){                                   //attack 1
    dmg += 2;
    //apply vulnerable
    applyVuln();
    return dmg;
}
int Stonipede::Attack2(int dmg){                                   //attack 2
    dmg += ceil(def/2);
    return dmg;
}


int Stonipede::Special(int dmg){                                    //special attack
    def = ceil(def * 1.2);
    dmg += def;
    currHP += 10;
    if(currHP > maxHP){
        currHP = maxHP;
    }
    return dmg;
}