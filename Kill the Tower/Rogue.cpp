#include "Rogue.h"


Rogue::Rogue() : Character("Rogue"){                                   //constructor

    atk = 3;
    def = 1;
    energy = 7;
    maxEnergy = 7;
    maxHP = 100;
    currHP = maxHP;
    dodge = 15;
    dodgecap = 55;
    resource = 0; //max 5
    maxResource = 5;
    floor = 1;

}
Rogue::Rogue(string name) : Character(name){                            //overloaded constructor

    atk = 3;
    def = 1;
    energy = 7; //increase by 1 per floor
    maxEnergy = 7;
    maxHP = 100;
    currHP = maxHP;
    dodge = 15;
    dodgecap = 55;
    resource = 0; //max 5
    maxResource = 5;
    floor = 1;

}

void Rogue::calculateDamage(string atkType){                                //calculates damage based on selected utility
    dmg = atk;
    switch(tolower(atkType.at(0))){
        case('k'): //knife
            dmg += 32 + floor;
            break;
        
        case('d'):
            if(energy < 1){
                cout << "Not enough utility uses!" << endl << endl;
                battleMenu();
            }
            else{
                dmg = Dagger(dmg);
                energy--;
            }
            break;
        
        case('b'):
            if(energy < 3){
                cout << "Not enough utility uses!" << endl << endl;
                battleMenu();
            }
            else{
                dmg = Bolas(dmg);
                energy -= 3;
            }
            break;

        case('s'):
            if(energy < 2){
                cout << "Not enough utility uses!" << endl << endl;
                battleMenu();
            }
            else{
                dmg = smokeBomb(dmg);
                energy -= 2;
            }
            break;

    }
}



void Rogue::resourceAbility(){                              //special ability!!! poggers
    if(resource < maxResource){
        cout << "Not enough sneak!" << endl;
        battleMenu();
    }
    else{
        if(energy < 1){
            cout << "Not enough utility uses!" << endl;
        }
        else{
            resource = 0;
            atk += 7;
            dmg = atk;
            int origDmg = dmg;
            dmg += Bolas(origDmg);
            dmg += Dagger(origDmg);
            dmg += smokeBomb(origDmg);
            energy--;
        }
    }
}


int Rogue::Dagger(int dmg){                         //high base damage, poisons
    dmg += 23+ floor*3;
    applyPoison();
    return dmg;
}

int Rogue::smokeBomb(int dmg){                      //low base damage, increases dodge
    dmg += 12+ floor*3;
    dodge += 15;
    if (dodge > dodgecap){
        dodge = dodgecap;
        cout << "Dodge chance capped!" << endl;
    }
    return dmg;
}

int Rogue::Bolas(int dmg){                          //higher base damage, applies vulnerable
    dmg += 27+ floor*4;
    applyVuln();
    return dmg;
}

void Rogue::Potion(){                                   //heal a flat amount of hp
    if(energy < 1){
        cout << "Not enough utility uses!" << endl;
        utilMenu();
    }
    energy--;
    currHP += 43;
    if(currHP > maxHP){
        currHP = maxHP;
    }
}

void Rogue::Elixir(){                                   //heal to full and cleanse all status effects
    if(energy < 7){
        cout << "Not enough utility uses!" << endl;
        utilMenu();
    }
    energy -= 7;
    currHP = maxHP;
    poisoned = false;
    weak = false;
    vuln = false;
}
void Rogue::battleStats(){                                      //print stats relevant to battle
    cout << name << ": HP - " << currHP << "/" << maxHP << " CUN - " << atk << " DEF - " << def << " Utility - " << energy << "/" << maxEnergy << endl;
    cout << "Sneak - " << resource << "/" << maxResource << endl;
}
void Rogue::battleMenu(){                                       //print battle menu and prompt for action choices
    try{
        cout << ">Utility   >Special   >Status" << endl;
        string option;
        cin >> option;
        Lowercase(option);
        if(option != "utility"){
            if(option != "special"){
                if(option != "status"){
                    throw InvalidActionError();
                }
            }
        }
        if (option == "utility"){
            utilMenu();
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
        cout << "Invalid option! Type Utility, Special, or status!" << endl;
        battleMenu();
    }
}
void Rogue::utilMenu(){                                          //print menu for utility and prompt for actions
    try{
        cout << ">Dagger   >Smoke   >Bolas   >Knife   >Potion   >Elixir   >Return" << endl;
        string option;
        cin >> option;
        Lowercase(option);
        if(option != "dagger"){
            if(option != "smoke"){
                if(option != "bolas"){
                    if(option != "knife"){
                        if(option != "potion"){
                            if(option != "elixir"){
                                if(option != "return"){
                                    throw InvalidActionError();
                                }
                            }
                        }
                    }
                }
            }
        }
        if(option == "return"){
            battleMenu();
        }
        if(option == "potion" || option == "elixir"){
            if(option == "potion"){
                Potion();
                dmg = 0;
            }
            else{
                Elixir();
                dmg = 0;
            }
        }
        else{
            calculateDamage(option);
        }
    }
    catch(InvalidActionError){
        cout << "Invalid option! Type Dagger, Smoke, Bolas, Knife, Potion, Elixir, or Return" << endl;
        utilMenu();
    }
}
void Rogue::afterBattle(){                              //level up
    floor++;
    atk = 3 + (floor/2);
    def = 1 + ceil(floor/2);
    energy++;
    maxEnergy++;
    maxHP = 100 + floor*10;
    currHP += floor*10;
    if(currHP > maxHP){
        currHP = maxHP;
    }
    dodge = 15 + floor + 2;
    dodgecap = 55 + ceil(floor * 2.15);
    if(dodgecap > 90){
        dodgecap = 90;
    }
    poisoned = false;
    weak = false;
    vuln = false;
    applypoison = false;
    applyweak = false;
    applyvuln = false;
}
void Rogue::printStats(){                           //print status of character
    cout << endl;
    cout << "Rogue" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << currHP << "/" << maxHP << endl;
    cout << "Defense: " << def << endl;
    cout << "Cunning: " << atk << endl;
    cout << "Utility: " << energy << "/" << maxEnergy << endl;
    cout << "Sneak: " << resource << "/" << maxResource << endl;
    cout << "Floor: " << floor << endl;
    cout << endl;
}
void Rogue::save(){                                                 //save character values to file
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
        fout << "Rogue" << endl;
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