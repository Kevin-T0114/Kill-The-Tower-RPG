#ifndef DREADGON_H
#define DREADGON_H
#include "Enemy.h"

class Dreadgon : public Enemy{
public:
    Dreadgon();                              //dreadgon constructors and attacks and damage calculations
    Dreadgon(int floor);
    int Attack(int);
    int Attack2(int);
    int Special(int);
    void dmgCalc();
};


#endif