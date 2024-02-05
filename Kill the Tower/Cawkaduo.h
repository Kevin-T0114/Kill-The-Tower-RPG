#ifndef CAWKADUO_H
#define CAWKADUO_H
#include "Enemy.h"

class Cawkaduo : public Enemy{
public:
    Cawkaduo();                                           //cawkaduo constructors and attacks and damage calculations
    Cawkaduo(int floor);
    int Attack(int);
    int Attack2(int);
    int Special(int);
    void dmgCalc();

};



#endif