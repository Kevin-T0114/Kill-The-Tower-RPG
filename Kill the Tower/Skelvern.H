#ifndef Skelvern_H
#define Skelvern_H
#include "Enemy.h"

class Skelvern : public Enemy{
public:
    Skelvern();                              //skelvern constructors and attacks and damage calculations
    Skelvern(int floor);
    int Attack(int);
    int Attack2(int);
    int Special(int);
    void dmgCalc();
};

#endif