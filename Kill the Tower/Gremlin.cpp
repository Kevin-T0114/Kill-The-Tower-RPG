#include "Gremlin.h"

Gremlin::Gremlin() : Enemy("Gremlin"){                              //default constructor
    maxHP = 120;
    currHP = maxHP;
    def = 5;
    atk = 8;
    specialPts = 1;
}



Gremlin::Gremlin(int floor) : Enemy("Gremlin"){                     //overloaded constructor
    maxHP = ceil(120 * (1 + floor*0.15));
    currHP = maxHP;
    def = ceil(5 * (1 + floor*0.10));
    atk = ceil(8 * (1 + floor*0.20));
    specialPts = 1;

}

void Gremlin::dmgCalc(){                                            //damage calculations based on random attack
    dmg = atk;
    if(specialPts == 3){
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
int Gremlin::Attack(int dmg){                                   //attack 1
    dmg += 8;
    currHP += 12;
    if(currHP > maxHP){
        currHP = maxHP;
    }
    return dmg;
}

int Gremlin::Attack2(int dmg){                                   //attack 2
    dmg += 2;
    atk += 2;
    //apply weak
    applyWeak();
    return dmg;
}

int Gremlin::Special(int dmg){                                    //special attack
    dmg = Attack(dmg) * 2;
    atk += 5;
    return dmg;
}