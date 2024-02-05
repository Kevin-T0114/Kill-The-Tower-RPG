#ifndef IMP_H
#define IMP_H

#include "Enemy.h"

class Imp : public Enemy{
public:
    Imp();                              //imp constructors and attacks and damage calculations
    Imp(int floor);
    int Attack(int);
    int Attack2(int);
    int Special(int);
    void dmgCalc();
};


#endif