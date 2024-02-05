#ifndef STEELIPEDE_H
#define STEELIPEDE_H
#include "Enemy.h"

class Steelipede : public Enemy{
public:
    Steelipede();                              //steelipede constructors and attacks and damage calculations
    Steelipede(int floor);
    int Attack(int);
    int Attack2(int);
    int Special(int);
    void dmgCalc();
};


#endif