#include <iostream>
#include "MainGameFunctions.h"

using namespace std;
int main(){
    MainGameMenu();                                                                                 //Game start
    while(true){ 
        if(isLoadMenu){                                                                              //if the loadmenu variable is true, create a new character with all the values in the file
            ifstream fin(LoadFile);
            if(!fin.is_open()){                                                                     //if file is not open, return to main menu
                cout << "File not found! Returning to main menu" << endl;
                MainGameMenu();
            }
            string classType;
            fin >> classType;                                                                     //check what class the character in the file is
            if(classType == "Berserker"){
                Character* berserker = new Berserker;
                player = berserker;
                player = static_cast<Berserker*>(player);                                         //cast character pointer into berserker pointer and load values
                int loadstr;
                int loadstam;
                int loadmaxstam;
                int loadrage;
                fin >> loadname;
                fin >> loadHP;
                fin >> loadmaxHP;                
                fin >> loaddef;
                fin >> loadstr;
                fin >> loadstam;
                fin >> loadmaxstam;
                fin >> loadrage;
                fin >> loadfloor;
                player->setName(loadname);
                player->setCurrHP(loadHP);
                player->setMaxHP(loadmaxHP);
                player->setDefense(loaddef);
                player->setAtkStat(loadstr);
                player->setResource(loadrage);
                player->setEnergy(loadstam);
                player->setMaxEnergy(loadmaxstam);
                player->setFloor(loadfloor);
                player->printStats();
            }
            else if(classType == "Scholar"){
                Character* scholar = new Scholar; 
                player = scholar;
                player = static_cast<Scholar*>(player);                                             //cast character pointer into scholar pointer and load values
                int loadint;
                int loadmana;
                int loadmaxmana;
                int loadpwr;
                fin >> loadname;
                fin >> loadHP;
                fin >> loadmaxHP;
                fin >> loaddef;
                fin >> loadint;
                fin >> loadmana;
                fin >> loadmaxmana;
                fin >> loadpwr;
                fin >> loadfloor;
                player->setName(loadname);
                player->setCurrHP(loadHP);
                player->setMaxHP(loadmaxHP);
                player->setDefense(loaddef);
                player->setAtkStat(loadint);
                player->setResource(loadpwr);
                player->setEnergy(loadmana);
                player->setMaxEnergy(loadmaxmana);
                player->setFloor(loadfloor);
                player->printStats();
            }
            else if(classType == "Rogue"){
                Character* rogue = new Rogue;
                player = rogue;
                player = static_cast<Rogue*>(player);                                               //cast character pointer into rogue pointer and load values
                int loadcun;
                int loadutil;
                int loadmaxutil;
                int loadsneak;
                fin >> loadname;
                fin >> loadHP;
                fin >> loadmaxHP;
                fin >> loaddef;
                fin >> loadcun;
                fin >> loadutil;
                fin >> loadmaxutil;
                fin >> loadsneak;
                fin >> loadfloor;
                player->setName(loadname);
                player->setCurrHP(loadHP);
                player->setMaxHP(loadmaxHP);
                player->setDefense(loaddef);
                player->setAtkStat(loadcun);
                player->setResource(loadsneak);
                player->setEnergy(loadutil);
                player->setMaxEnergy(loadmaxutil);
                player->setFloor(loadfloor);
                player->printStats();
            }
        }
        else if(isCharacterCreation){                                                               //if charactercreation variable is true, create a character based on what the player chose
            if(isBerserker){
                Character* berserker = new Berserker(playerName);
                player = berserker;
                player = static_cast<Berserker*>(player);
                
            }
            else if(isRogue){
                Character* rogue = new Rogue(playerName);
                player = rogue;
                player = static_cast<Rogue*>(player);
            }
            else if(isScholar){
                Character* scholar = new Scholar(playerName);
                player = scholar;
                player = static_cast<Scholar*>(player);
            }
        }
        isLoadMenu = false;                                                                         //make these values false when character creation is complete
        isCharacterCreation = false;
        bool isBerserker = false;
        bool isRogue = false;
        bool isScholar = false;
        InGameMenu();                                                                               //start main game loop with menu
        cout << endl;
        if(inGameMenuChoice == "continue"){                                                         //enter battle
            if(player->getFloor() < 5){                                                             //depending on which floor the player is on, create a random enemy from different sets of enemies; 3 on 1-4, 1 on 5, 3 on 6-9, final boss on 10
                srand(time(0));
                int random;
                random = rand() % 3;
                if (random == 0){
                    Enemy* gremlin = new Gremlin(player->getFloor());
                    enemy = gremlin;
                    enemy = static_cast<Gremlin*>(enemy);
                }
                else if(random == 1){
                    Enemy* cawkaduo = new Cawkaduo(player->getFloor());
                    enemy = cawkaduo;
                    enemy = static_cast<Cawkaduo*>(enemy);
                }
                else if(random == 2){
                    Enemy* stonipede = new Stonipede(player->getFloor());
                    enemy = stonipede;
                    enemy = static_cast<Stonipede*>(enemy);
                }
            }
            if(player->getFloor() == 5){
                Enemy* skelvern = new Skelvern;
                enemy = skelvern;
                enemy = static_cast<Skelvern*>(enemy);
            }
            if(player->getFloor() > 5 && player->getFloor() < 10){
                srand(time(0));
                int random;
                random = rand() % 3;
                if (random == 0){
                    Enemy* imp = new Imp(player->getFloor());
                    enemy = imp;
                    enemy = static_cast<Imp*>(enemy);
                }
                else if(random == 1){
                    Enemy* cawkatrio = new Cawkatrio(player->getFloor());
                    enemy = cawkatrio;
                    enemy = static_cast<Cawkatrio*>(enemy);
                }
                else if(random == 2){
                    Enemy* steelipede = new Steelipede(player->getFloor());
                    enemy = steelipede;
                    enemy = static_cast<Steelipede*>(enemy);
                }
            }
            if(player->getFloor() == 10){
                Enemy* dreadgon = new Dreadgon;
                enemy = dreadgon;
                enemy = static_cast<Dreadgon*>(enemy);
            }                                                               //end of enemy creation
            while(true){                                                    //battle loop
                player->Poison();                                           //inflict poison damage if poisoned
                if(player->getCurrHP() <= 0){                               //check for player and enemy death
                    player->Death();
                    delete player;                                          //delete allocated memory for the enemy and player
                    delete enemy;
                    exit(0);                                                //terminate program upon death
                }
                player->battleStats();                                      //show general player and enemy stats
                cout << endl;
                enemy->stats();
                cout << endl;
                cout << "--------------------------------------------------------------------------------" << endl;
                cout << "Player turn!" << endl;                             //player turn
                player->resetapplyPoison();                                 //reset all player triggers for applying statuses
                player->resetapplyVuln();
                player->resetapplyWeak();
                int origplayeratk = player->getAtkStat();                   //create variables to use for detecting stat changes
                int origplayerHP = player->getCurrHP();
                player->battleMenu();                                       //player chooses actions
                cout << endl;
                player->Weak();                                             //checks if player is weak (deals less damage)
                int playerdmg = player->getDmg() - enemy->getDef();
                if(enemy->isVuln()){                                        //if enemy is vulnerable deal more damage
                    playerdmg = ceil(playerdmg * 1.15);
                }
                if (playerdmg < 0){
                    playerdmg = 0;
                }
                enemy->setCurrHP(enemy->getCurrHP() - playerdmg);                   //display interactions between player and enemy, stat changes, and status effects
                if (playerdmg == 0){
                    cout << player->getName() << " dealt 0 damage!" << endl;
                    cout << endl;
                }
                else{
                    cout << player->getName() << " deals " << playerdmg << " to " << enemy->getName() << "!" << endl;
                }
                if(player->getAtkStat() > origplayeratk){
                    cout << player->getName() << " becomes more powerful by " << player->getAtkStat() - origplayeratk << endl;
                    cout << endl;
                }
                if(player->getCurrHP() > origplayerHP){
                    cout << player->getName() << " healed for " << player->getCurrHP() - origplayerHP << endl;
                    cout << endl;
                }
                if(player->getApplyPoison()){
                    enemy->setPoisoned();
                    cout << player->getName() << " poisoned " << enemy->getName() << "!" << endl;
                    cout << endl;
                }
                if(player->getApplyVuln()){
                    enemy->setVuln();
                    cout << player->getName() << " exploited " << enemy->getName() << "!" << endl;
                    cout << endl;
                }
                if(player->getApplyWeak()){
                    enemy->setWeak();
                    cout << player->getName() << " weakened " << enemy->getName() << "!" << endl;
                    cout << endl;
                }
                if(player->getResource() < player->getMaxResource()){                       //makes player special ability points stop at the max point value when incrementing
                    player->incResource();
                    cout << endl;
                }
                player->incEnergy();                                                        //increment energy for attacks after turn
                player->resetWeak();                                                        //weakness lasts until turn ends
                if(player->getCurrHP() <= 0){                                               //check for player and enemy death
                    player->Death();
                    delete player;
                    delete enemy;
                    exit(0);
                }
                cout << endl;                                                               //check if poison damage kills enemy at start of enemy turn
                enemy->Poison();
                if(enemy->getCurrHP() <= 0){
                    player->afterBattle();                                                  //if enemy dies, level up player and if the enemy is final boss, play victory screen
                    enemy->Death();
                    cout << endl;
                    delete enemy;
                    if(player->getFloor() == 11){
                        GameVictory();
                    }
                    break;
                }
                cout << "--------------------------------------------------------------------------------" << endl;
                cout << "Enemy Turn!" << endl;                                              //enemy turn
                cout << endl;
                enemy->resetapplyPoison();                                                  //reset all status effect triggers
                enemy->resetapplyVuln();
                enemy->resetapplyWeak();
                enemy->Weak();                                                              //check for weakness
                
                int origenemyHP = enemy->getCurrHP();                                       //temporary values to track stat changes
                int origenemydef = enemy->getDef();
                int origenemyatk = enemy->getAtk();
                int dodgechance = player->getDodge();
                srand(time(0));
                if(rand()%101 < dodgechance){                                               //determines if enemy will hit or not
                    cout << enemy->getName() << " missed!" << endl;
                    cout << endl;
                }
                else{
                    enemy->dmgCalc();                                                       //output enemy attacks, output enemy stat changes and player status effect changes
                    int enemydmg = enemy->getDmg() - player->getDefense();
                    if(player->isVuln()){
                        enemydmg * ceil(enemydmg * 1.15);
                    }
                    if (enemydmg < 0){
                        enemydmg = 0;
                    }
                    player->setCurrHP(player->getCurrHP() - enemydmg);
                    if(enemydmg == 0){
                        cout << enemy->getName() << " dealt 0 damage!" << endl;
                        cout << endl;
                    }
                    else{
                        cout << enemy->getName() << " attacks " << player->getName() << " for " << enemydmg << " damage!" << endl;
                        cout << endl;
                    }
                    if(enemy->getCurrHP() > origenemyHP){
                        cout << enemy->getName() << " healed for " << enemy->getCurrHP() - origenemyHP << endl;
                        cout << endl;
                    }
                    if(enemy->getAtk() > origenemyatk){
                        cout << enemy->getName() << " becomes more powerful by " << enemy->getAtk() - origenemyatk << endl;
                        cout << endl;
                    }
                    if(enemy->getDef() > origenemydef){
                        cout << enemy->getName() << " gets sturdier by " << enemy->getDef() - origenemydef << endl;
                        cout << endl;
                    }
                    if(enemy->getApplyPoison()){
                        player->setPoisoned();
                        cout << enemy->getName() << " poisoned " << player->getName() << "!" << endl;
                        cout << endl;
                    }
                    if(enemy->getApplyVuln()){
                        player->setVuln();
                        cout << enemy->getName() << " exploited " << player->getName() << "!" << endl;
                        cout << endl;
                    }
                    if(enemy->getApplyWeak()){
                        player->setWeak();
                        cout << enemy->getName() << " weakened " << player->getName() << "!" << endl;
                        cout << endl;
                    }
                }
                enemy->resetWeak();                                                     //end of turn; weakness ends, increment points needed for enemy special attack
                enemy->incSpecialPts();
            }
        }

    }
    return 0;

}
