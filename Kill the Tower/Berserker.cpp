#include "Berserker.h"

Berserker::Berserker() : Character("Berserker") {                   //default constructor
    atk = 2;
    def = 3;
    energy = 100;
    maxEnergy = 100;
    maxHP = 100;
    currHP = maxHP;
    dodge = 10;
    resource = 0;
    maxResource = 6;
    floor = 1;

}
Berserker::Berserker(string name) : Character(name) {               //overloaded constructor
    atk = 2;
    def = 3;
    energy = 100;
    maxEnergy = 100;
    maxHP = 100;
    currHP = maxHP;
    dodge = 10;
    resource = 0;
    maxResource = 6;
    floor = 1;
}
void Berserker::calculateDamage(string atkType){                    //damage calculations based on selected attack, if not enough energy, select another action
    dmg = atk;
    switch(tolower(atkType.at(0))){
        case('b'):
            if(energy < 75){
                cout << "Not enough stamina!" << endl << endl;
                battleMenu();
            }
            else{
                dmg = bashAtk(dmg); 
            }
            break;
        case('s'):
            if(energy < 30){
                cout << "Not enough stamina!" << endl << endl;
                battleMenu();
            }
            else{
                dmg = slashAtk(dmg);
            }
            break;
        case('v'):
            if(energy < 35){
                cout << "Not enough stamina!" << endl << endl;
                battleMenu();
            }
            else{
                dmg = vampiricAtk(dmg);
            }
            break;
        case('n'):                                                //normal attack
            dmg += 12;
            break;
    }
    
}


void Berserker::resourceAbility(){                                  //special ability POGGERS!!!
    if(resource < maxResource){
        cout << "Not enough rage!" << endl;
        battleMenu();
    }
    else{
        resource = 0;                                               //reset rage bar to 0
        atk += 1; 
        atk *= (3 + ceil(floor/2));
        def -= 5;                                                   
        if(def < 0){                                                //if negative, set to 0
            def = 0;
        }
        energy += 40;
        currHP += 20;
    }
}


int Berserker::bashAtk(int dmg){                                    //high base damage, applies vulnerable
    energy -= 75;
    cout << "75 stamina used!" << endl;
    int basedmg = 46+ floor * 3;
    dmg += basedmg;
    dmg = ceil(dmg * 1.5);
    applyVuln();                        
    return dmg;
}

int Berserker::slashAtk(int dmg){                                   //medium base damage, can crit
    energy -= 30;
    cout << "30 stamina used!" << endl;
    int basedmg = 37+ floor * 3;
    dmg += basedmg;
    int crit = 0;
    srand(time(0));
    crit = rand() % 101;
    if (crit <= 30){
        dmg *= 2;
        cout << "Critical Hit!" << endl;
    }
    else{
        dmg = ceil(dmg * 1.2);
    }

    return dmg;
}

int Berserker::vampiricAtk(int dmg){                                //lower base damage, can life steal
    energy -= 35;
    cout << "35 stamina used!" << endl;
    int basedmg = 26 + floor*3;
    dmg += basedmg;
    currHP += dmg;
    if (currHP > maxHP){
        currHP = maxHP;
    }
    return dmg;
}

void Berserker::battleStats(){                                      //print stats relevant to battle
    cout << name << ": HP - " << currHP << "/" << maxHP << " STR - " << atk << " DEF - " << def << " Stamina - " << energy << "/" << maxEnergy << endl;
    cout << "Rage - " << resource << "/" << maxResource << endl;
}

void Berserker::battleMenu(){                                       //print battle menu and prompt for action choices
    try{
        cout << ">Attack   >Special   >Status" << endl;
        string option;
        cin >> option;
        Lowercase(option);
        if(option != "attack"){
            if(option != "special"){
                if(option != "status"){
                    throw InvalidActionError();
                }
            }
        }
        if(option != "special"){
            if(option != "attack"){
                if(option != "status"){
                    throw InvalidActionError();
                }
            }
        }
        if(option != "status"){
            if(option != "special"){
                if(option != "attack"){
                    throw InvalidActionError();
                }
            }
        }
        if (option == "attack"){
            atkMenu();
        }
        else if(option == "special"){
            resourceAbility();
        }
        else if(option == "status"){
            printStats();
            battleMenu();
        }
    }
    catch(InvalidActionError){
        cout << "Invalid Option! Type Attack, Special, or Status" << endl;
        battleMenu();
    }
}
void Berserker::atkMenu(){                                          //print menu for attacks and prompt for actions
    try{
        cout << ">Slash   >Bash   >Vampiric   >Normal   >Return" << endl;
        string option;
        cin >> option;
        Lowercase(option);
        if(option != "slash"){
            if(option != "bash"){
                if(option != "vampiric"){
                    if(option!= "normal"){
                        if(option != "return"){
                            throw InvalidActionError();
                        }
                    }
                }
            }
        }
        if(option == "return"){
            battleMenu();
        }
        else{
            calculateDamage(option);
        }
    }
    catch(InvalidActionError){
        cout << "Invalid Option! Type Slash, Bash, Vampiric, Normal, or Return" << endl;
        atkMenu();
    }
}
void Berserker::afterBattle(){                              //level up
    floor++;
    atk = 2 + ceil(floor/2);
    def = 3 + ceil(floor/3);
    energy += floor*10;
    maxEnergy = 100 + floor*10;
    if(energy > maxEnergy){
        energy = maxEnergy;
    }
    maxHP = 100 + floor*15;
    currHP += floor*15;
    if(currHP > maxHP){
        currHP = maxHP;
    }
    poisoned = false;
    weak = false;
    vuln = false;
    applypoison = false;
    applyweak = false;
    applyvuln = false;
}
void Berserker::printStats(){                           //print status of character
    cout << endl;
    cout << "Berserker" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << currHP << "/" << maxHP << endl;
    cout << "Defense: " << def << endl;
    cout << "Strength: " << atk << endl;
    cout << "Stamina: " << energy << "/" << maxEnergy << endl;
    cout << "Rage: " << resource << "/" << maxResource << endl;
    cout << "Floor: " << floor << endl;
    cout << endl;
}
void Berserker::save(){                                                 //save character values to file
    try{
        cout << "Choose which file to save to (Type 1, 2, or 3)" << endl;
        string f;
        cin >> f;
        if(f != "1"){
            if(f != "2"){
                if(f != "3"){
                    throw Not123Error();
                }
            }
        }
        f += ".txt";
        ofstream fout(f);
        fout << "Berserker" << endl;
        fout << name << endl;
        fout << currHP << endl;
        fout << maxHP << endl;
        fout << def << endl;
        fout << atk << endl;
        fout << energy << endl;
        fout << maxEnergy << endl;
        fout << resource << endl;
        fout << floor << endl; 
        fout.close();
    }
    catch(Not123Error){
        cout << "Please select 1, 2, or 3!" << endl;
        save();
    }
}