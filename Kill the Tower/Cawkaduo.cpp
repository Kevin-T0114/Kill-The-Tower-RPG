#include "Cawkaduo.h"
Cawkaduo::Cawkaduo() : Enemy("Cawkaduo"){                              //default constructor
//currHP maxHP, def, atk, dmg, specialPts;
    maxHP = 110;
    currHP = maxHP;
    def = 3;
    atk = 2;
    specialPts = 0;
}



Cawkaduo::Cawkaduo(int floor) : Enemy("Cawkaduo"){                     //overloaded constructor
    maxHP = ceil(110 * (1 + floor*0.15));
    currHP = maxHP;
    def = ceil(3 * (1 + floor*0.10));
    atk = ceil(2 * (1 + floor*0.10));
    specialPts = 0;

}

void Cawkaduo::dmgCalc(){                                            //damage calculations based on random attack
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
int Cawkaduo::Attack(int dmg){                                          //caw
    dmg += 2;
    atk += 8;
    cout << "Caw" << endl << endl;
    return dmg;
}
int Cawkaduo::Attack2(int dmg){                                            //caw
    dmg += 10;
    cout << "Caw" << endl << endl;
    return dmg;
}


int Cawkaduo::Special(int dmg){                                             //cawcaw
    dmg += 2;
    currHP += 30;
    if(currHP > maxHP){
        currHP = maxHP;
    }
    cout << "Caw Caw" << endl << endl;
    return dmg;
}