#include "Dreadgon.h"

Dreadgon::Dreadgon() : Enemy("Dreadgon"){                              //default constructor

    maxHP = 500;
    currHP = maxHP;
    def = 55;
    atk = 10;
    specialPts = 0;
}



Dreadgon::Dreadgon(int floor) : Enemy("Dreadgon"){                     //overloaded constructor
    maxHP = 500;
    currHP = maxHP;
    def = 55;
    atk = 10;
    specialPts = 0;

}

void Dreadgon::dmgCalc(){                                            //damage calculations based on random attack
    dmg = atk;
    if(specialPts == 7){
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
int Dreadgon::Attack(int dmg){                                    //attack 1
    dmg += 7;
    def = ceil(def * 0.85);
    applyWeak();
    applyVuln();
    return dmg;
}
int Dreadgon::Attack2(int dmg){                                    //attack 2
    dmg = ceil(dmg*1.5);
    currHP += dmg;
    if(currHP > maxHP){
        currHP = maxHP;
    }
    def = ceil(def*.9);
    applyPoison();
    return dmg;
}


int Dreadgon::Special(int dmg){                                    //special attack
    currHP += 100;
    dmg += 10;
    atk += def;
    atk *= 2;
    def -= 50;
    if (def < 0){
        def = 0;
    }
    if(currHP > maxHP){
        currHP = maxHP;
    }
    return dmg;
}