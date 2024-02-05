#ifndef GREMLIN_H
#define GREMLIN_H
#include "Enemy.h"


class Gremlin : public Enemy{
public:
    Gremlin();                              //gremlin constructors and attacks and damage calculations
    Gremlin(int floor);
    int Attack(int);
    int Attack2(int);
    int Special(int);
    void dmgCalc();
};


#endif