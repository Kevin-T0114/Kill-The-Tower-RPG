#include "Steelipede.h"
Steelipede::Steelipede() : Enemy("Steelipede"){                              //default constructor
    maxHP = 160;
    currHP = maxHP;
    def = 18;
    atk = 2;
    specialPts = 0;
}



Steelipede::Steelipede(int floor) : Enemy("Steelipede"){                     //overloaded constructor
    maxHP = ceil(160 * (1 + floor*0.20));
    currHP = maxHP;
    def = ceil(18 * (1 + floor*0.15));
    atk = ceil(2 * (1 + floor*0.15));
    specialPts = 0;

}

void Steelipede::dmgCalc(){                                            //damage calculations based on random attack
    dmg = atk;
    if(specialPts == 4){
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
int Steelipede::Attack(int dmg){                                   //attack 1
    dmg += 3;
    //apply vulnerable
    //apply weak
    applyVuln();
    applyWeak();
    return dmg;
}
int Steelipede::Attack2(int dmg){                                   //attack 2
    def += 2;
    atk--;
    if(atk < 0){
        atk = 0;
    }
    dmg += ceil(def/2);
    return dmg;
}


int Steelipede::Special(int dmg){                                    //special attack
    def = ceil(def * 1.38);
    dmg += def;
    currHP += ceil(maxHP/4);
    if(currHP > maxHP){
        currHP = maxHP;
    }
    return dmg;
}