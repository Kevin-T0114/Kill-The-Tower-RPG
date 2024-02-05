#ifndef STONIPEDE_H
#define STONIPEDE_H
#include "Enemy.h"

class Stonipede : public Enemy{
public:
    Stonipede();                              //stonipede constructors and attacks and damage calculations
    Stonipede(int floor);
    int Attack(int);
    int Attack2(int);
    int Special(int);
    void dmgCalc();
};


#endif