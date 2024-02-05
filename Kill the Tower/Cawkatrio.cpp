#include "Cawkatrio.h"
Cawkatrio::Cawkatrio() : Enemy("Cawkatrio"){                              //default constructor
    maxHP = 125;
    currHP = maxHP;
    def = 2;
    atk = 1;
    specialPts = 0;
}



Cawkatrio::Cawkatrio(int floor) : Enemy("Cawkatrio"){                     //overloaded constructor
    maxHP = ceil(125 * (1 + floor*0.20));
    currHP = maxHP;
    def = ceil(2 * (1 + floor*0.15));
    atk = ceil(1 * (1 + floor*0.15));
    specialPts = 0;

}

void Cawkatrio::dmgCalc(){                                            //damage calculations based on random attack
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
int Cawkatrio::Attack(int dmg){                             //CAW
    dmg += 4;
    atk += 10;
    cout << "CAW" << endl << endl;
    return dmg;
}
int Cawkatrio::Attack2(int dmg){                                //CAW
    dmg += 12;
    currHP += dmg;
    if(currHP > maxHP){
        currHP = maxHP;
    }
    cout << "CAW" << endl << endl;
    return dmg;
}


int Cawkatrio::Special(int dmg){                                //CAWCAWCAW
    atk = ceil(atk * 2.2);
    def -= 10;
    if (def < 0){
        def = 0;
    }
    currHP += 50;
    if(currHP > maxHP){
        currHP = maxHP;
    }
    cout << "CAW CAW CAW" << endl << endl;
    return dmg;
}