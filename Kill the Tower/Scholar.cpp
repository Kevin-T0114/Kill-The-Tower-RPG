#include "Scholar.h"

Scholar::Scholar() : Character("Scholar") {                         //default constructor
    atk = 2;
    def = 2;
    energy = 100;
    maxEnergy = 100;
    maxHP = 110;
    currHP = maxHP;
    dodge = 10;
    resource = 0; //max 6
    maxResource = 6;
    floor = 1;

}
Scholar::Scholar(string name) : Character(name) {                   //overloaded constructor
    atk = 2;
    def = 2;
    energy = 100;
    maxEnergy = 100;
    maxHP = 110;
    currHP = maxHP;
    dodge = 10;
    resource = 0; //max 6
    maxResource = 6;
    floor = 1;
}
void Scholar::calculateDamage(string atkType){                              //calculate damage based on spell
    dmg = atk;
    switch(tolower(atkType.at(0))){
        case('e'):
            if(energy < 45){
                cout << "Not enough mana!" << endl << endl;
                battleMenu();
            }
            else{
                dmg = Explosion(dmg);
            }
            break;
        
        case('s'):
            if(energy < 30){
                cout << "Not enough mana!" << endl << endl;
                battleMenu();
            }
            else{
                dmg = Smite(dmg);
            }
            break;

        case('t'):
            if(energy < 40){
                cout << "Not enough mana!" << endl << endl;
                battleMenu();
            }
            else{
                dmg = Typhoon(dmg);
            }
            break;
        case('b'): //basic
            dmg += 12;
            break;
    }
}


void Scholar::resourceAbility(){                            //special ability POGGERS!!!
    if(resource < maxResource){
        cout << "Not enough power!" << endl;
        battleMenu();
    }
    else{
        resource = 0;
        atk += 15;
        energy += 60;
        if(energy > maxEnergy){
            energy = maxEnergy;
        }
        resourcespellMenu();
        dmg *= 2;
    }
}


int Scholar::Explosion(int dmg){                    //high base damage, can backfire and deal damage to self
    energy -= 60;
    int basedmg = 46+ ceil(floor*2.25);
    dmg += basedmg;
    srand(time(0));
    int failRate = rand() % 101;
    if(failRate <= 20){
        currHP -= ceil(basedmg/2);
        cout << endl << "The spell backfires! " << name << " takes 25 damage!" << endl;
        dmg = 0;
        return dmg;
    }
    return dmg;
}

int Scholar::Smite(int dmg){                        //medium base damage, chance to crit
    energy -= 30;
    int basedmg = 34+ floor*4;
    dmg += basedmg;
    srand(time(0));
    int crit = rand() % 101;
    if(crit <= 25){
        dmg = ceil(dmg*1.75);
        cout << "Critical Hit!" << endl;
    }
    return dmg;

}

int Scholar::Typhoon(int dmg){                          //lower base damage, chance to inflict weak
    energy -= 40;
    int basedmg = 32+ ceil(floor*2.5);
    dmg += basedmg;
    srand(time(0));
    int chance = rand() % 100;
    if(chance <= 50){
        applyWeak();
    }
    return dmg;
}

void Scholar::Heal(){                                   //heal spell
    if(energy < 50){
        cout << "Not enough mana!" << endl << endl;
        battleMenu();
    }
    else{
        energy -= 50;
        currHP += ceil(maxHP/2);
        if(currHP > maxHP){
            currHP = maxHP;
        }
    }
}
void Scholar::battleStats(){                                      //print stats relevant to battle
    cout << name << ": HP - " << currHP << "/" << maxHP << " INT - " << atk << " DEF - " << def << " Mana - " << energy << "/" << maxEnergy << endl;
    cout << "Stored Power - " << resource << "/" << maxResource << endl;
}
void Scholar::battleMenu(){                                       //print battle menu and prompt for action choices
    try{
        cout << ">Cast   >Special   >Status" << endl;
        string option;
        cin >> option;
        Lowercase(option);
        if(option != "cast"){
            if(option != "special"){
                if(option != "status"){
                       throw InvalidActionError();
                }
            }
        }
        if (option == "cast"){
            spellMenu();
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
        cout << "Invalid Option! Type Cast, Special, or Status!" << endl;
        battleMenu();
    }
}
void Scholar::spellMenu(){                                          //print menu for spells and prompt for actions
    try{
        cout << ">Explosion   >Typhoon   >Smite   >Heal   >Basic   >Return" << endl;
        string spell;
        cin >> spell;
        Lowercase(spell);
        if(spell != "explosion"){
            if(spell != "typhoon"){
                if(spell != "smite"){
                    if(spell != "heal"){
                        if(spell != "basic"){
                            if(spell != "return"){
                                throw InvalidActionError();
                            }
                        }
                    }
                }
            }
        }
        if(spell == "return"){
            battleMenu();
        }
        else if (spell == "heal"){
            Heal();
            dmg = 0;
        }
        else{
            calculateDamage(spell);
        }
    }
    catch(InvalidActionError){
        cout << "Invalid option! Type Explosion, Typhoon, Smite, Heal, Basic, or Return" << endl;
        spellMenu();
    }
}
void Scholar::resourcespellMenu(){                                          //print menu for spells used for special ability
    try{
        cout << "Select a spell to empower" << endl;
        cout << ">Explosion   >Typhoon   >Smite" << endl;
        string rspell;
        cin >> rspell;
        Lowercase(rspell);
        if(rspell != "explosion"){
            if(rspell != "typhoon"){
                if(rspell != "smite"){
                       throw InvalidActionError();
                }
            }
        }
        else{
            calculateDamage(rspell);
        }
    }
    catch(InvalidActionError){
        cout << "Invalid option! Type Explosion, Typhoon, or Smite!" << endl;
        resourcespellMenu();
    }
}
void Scholar::afterBattle(){                              //level up
    floor++;
    atk = 2 + floor;
    def = 2 + ceil(floor/2);
    energy += floor*15;
    maxEnergy = 100 + floor*15;
    if(energy > maxEnergy){
        energy = maxEnergy;
    }
    maxHP = 110 + floor*12;
    currHP += floor*12;
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
void Scholar::printStats(){                           //print status of character
    cout << endl;
    cout << "Scholar" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << currHP << "/" << maxHP << endl;
    cout << "Defense: " << def << endl;
    cout << "Intelligence: " << atk << endl;
    cout << "Mana: " << energy << "/" << energy << endl;
    cout << "storedPwr: " << resource << "/" << maxResource << endl;
    cout << "Floor: " << floor << endl;
    cout << endl;
}
void Scholar::save(){                                                 //save character values to file
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
        fout << "Scholar" << endl;
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