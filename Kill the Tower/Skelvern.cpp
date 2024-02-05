#include "Skelvern.H"

Skelvern::Skelvern() : Enemy("Skelvern"){                              //default constructor
//currHP maxHP, def, atk, dmg, specialPts;
    maxHP = 250;
    currHP = maxHP;
    def = 15;
    atk = 8;
    specialPts = 0;
}



Skelvern::Skelvern(int floor) : Enemy("Skelvern"){                     //overloaded constructor
    maxHP = 250;
    currHP = maxHP;
    def = 15;
    atk = 8;
    specialPts = 0;

}

void Skelvern::dmgCalc(){                                            //damage calculations based on random attack
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
int Skelvern::Attack(int dmg){                                   //attack 1
    dmg += 5;
    currHP += dmg;
    if(currHP > maxHP){
        currHP = maxHP;
    }
    return dmg;
}
int Skelvern::Attack2(int dmg){                                    //attack 2
    dmg += ceil(def * 1.3);
    def = ceil(def * 1.5);
    return dmg;
}


int Skelvern::Special(int dmg){                                    //special attack
    if(currHP < ceil(maxHP/3)){
        currHP += 50;
        def += 10;
        atk += 10;
    }
    else{
        dmg += 10;
        atk += 2;
        def += 3;
    }
    applyPoison();
    return dmg;
}