#ifndef CAWKATRIO_H
#define CAWKATRIO_H
#include "Enemy.h"

class Cawkatrio : public Enemy{
public:
    Cawkatrio();                              //cawkatrio constructors and attacks and damage calculations
    Cawkatrio(int floor);
    int Attack(int);
    int Attack2(int);
    int Special(int);
    void dmgCalc();

};



#endif
