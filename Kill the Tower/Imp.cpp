#include "Imp.h"
Imp::Imp() : Enemy("Imp"){                              //default constructor
    maxHP = 140;
    currHP = maxHP;
    def = 3;
    atk = 8;
    specialPts = 1;
}



Imp::Imp(int floor) : Enemy("Imp"){                     //overloaded constructor
    maxHP = ceil(140 * (1 + floor*0.20));
    currHP = maxHP;
    def = ceil(3 * (1 + floor*0.15));
    atk = ceil(8 * (1 + floor*0.15));
    specialPts = 1;

}

void Imp::dmgCalc(){                                            //damage calculations based on random attack
    dmg = atk;
    if(specialPts == 5){
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
int Imp::Attack(int dmg){                                   //attack 1
    dmg += 10;
    currHP += dmg;
    if(currHP > maxHP){
        currHP = maxHP;
    }
    return dmg;
}

int Imp::Attack2(int dmg){                                   //attack 2
    dmg += 4;
    atk += 7;
    //apply weak
    applyWeak();
    return dmg;
}

int Imp::Special(int dmg){                                    //special attack
    dmg = ceil(Attack(dmg) * 2.5);
    atk += 8;
    return dmg;
}