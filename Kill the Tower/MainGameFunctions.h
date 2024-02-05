#ifndef MAINGAMEFUNCTIONS_H
#define MAINGAMEFUNCTIONS_H
#include "Character.h"
#include "Characters.h"
#include "Enemy.h"
#include "Enemies.h"
Character* player;                              //declare/initialize all needed variables, pointers, and functions
Enemy* enemy;
bool GameLoop = true;
bool BattleLoop = true;
bool isLoadMenu = false;
bool isCharacterCreation = false;
bool isBerserker = false;
bool isRogue = false;
bool isScholar = false;
bool isReturn = false;
string inGameMenuChoice;
string LoadFile = "";
string playerName = "";
string loadname;
int loadHP;
int loadmaxHP;
int loaddef;
int loadfloor;
string lowercase(string word);
void ScholarSummary();
void BerserkerSummary();
void RogueSummary();
void characterCreationMenu();
void MenuLoad();
void MainGameMenu();
void GameVictory();
void InGameMenu();
class InvalidCharacterError {};                 //declare classes for exception errors
class NotYesNoError {};

string lowercase(string word){                  //returns the input word as lowercase
    string newWord = "";
    for (int i = 0; i < word.size(); i++){
        newWord += tolower(word.at(i));
    }
    return newWord;
}
void ScholarSummary(){                          //Displays a brief description of the Scholar class and asks for confirmation
    cout << endl;
    cout << "The Scholar is capable of casting mystical spells to assault the enemy. Harnessing powers from nature, the Scholar can critically strike with lightning, bathe the enemy in flames with an Explosion (with a chance for it to fail!), or drowning your enemies in floods to weaken them! Also possesses the ability to heal!" << endl;
    cout << "Special Ability: Unleash your inner power! Upon using this ability, intelligence temporarily increases drastically and the next ability deals double the amount of damage!" << endl;
    cout << "This ability can be used when the Scholar reaches their maximum stored power!" << endl;
    cout << endl;
    cout << "HP: 110/110 " << endl;
    cout << "Defense: 2" << endl;
    cout << "Intelligence: 2" << endl;
    cout << "Mana: 100/100"  << endl;
    cout << "Stored Power: 0/6" << endl;
    cout << "Basic Spell: Damage = 12  No Cost" << endl;
    cout << "Explosion: Damage = 51  Cost = 45 mana  Effect: 20 percent chance to backfire for half damage and deal 0 damage to enemy." << endl;
    cout << "Smite: Damage = 27  Cost = 30 mana  Effect: chance to critically strike for 1.75x damage." << endl;
    cout << "Typhoon: Damage = 32  Cost = 40 mana  Effect: 50 percent chance to weaken enemy." << endl;
    cout << "Heal: Heal for half of max HP  Cost = 50 mana" << endl;
    cout << endl;
    cout << "Do you wish to use this class? (Y/N)" << endl;

}
void RogueSummary(){                            //Displays a brief description of the Rogue class and asks for confirmation
    cout << endl;
    cout << "The Rogue is a trickster who deals with the enemy through tools and hidden weapons. Equipped with potions and elixirs to heal, the Rogue also conceals a deadly knife, a poisoned dagger, bolas to trip up the enemy into a vulnerable state, and smoke bombs to increase stealthiness!" << endl;
    cout << "Special Ability: Download the enemy and assault all out! Become more cunning to find a moment of weakness in which you can utilize the entirety of your arsenal at once!" << endl;
    cout << "This ability can be used when the Rogue reaches their maximum sneakiness!" << endl;
    cout << endl;
    cout << "HP: 100/100 " << endl;
    cout << "Defense: 1" << endl;
    cout << "Cunning: 3" << endl;
    cout << "Utility: 7/7"  << endl;
    cout << "Sneak: 0/5" << endl;
    cout << "Potion: Heal for 30 HP  Cost = 1 utility point" << endl;
    cout << "Elixir: Heal to full HP  Cost = 5 utility points  Effect: cleanse all status ailments." << endl;
    cout << "Knife: Damage = 32  No Cost" << endl;
    cout << "Dagger: Damage = 23  Cost = 1 utility points  Effect: poison enemy for damage each turn." << endl;
    cout << "Bolas: Damage = 27  Cost = 3 utility points  Effect: make enemy vulnerable." << endl;
    cout << "Smoke Bomb: Damage = 12  Cost = 2 utility points  Effect: increase innate dodge chance (capped at 55% but increases after each floor)." << endl;
    cout << endl;
    cout << "Do you wish to use this class? (Y/N)" << endl;

}
void BerserkerSummary(){                        //Displays a brief description of the Berserker class and asks for confirmation
    cout << endl;
    cout << "The Berserker boasts powerful attacks that instill fear upon any enemy. With attacks that specialize in life steal, critical strikes, and making the enemy more susceptible to attacks, the Berserker's battles either end in your death, or the enemy's." << endl;
    cout << "Special Ability: Shed your defenses to become stronger! Multiply your strength by your defense and decrease your defense to critically low levels (Defense resets to starting level after battle)!" << endl;
    cout << "This ability can be used when the Berserker reaches their maximum rage state!" << endl;
    cout << endl;
    cout << "HP: 100/100 " << endl;
    cout << "Defense: 3" << endl;
    cout << "Strength: 2" << endl;
    cout << "Stamina: 100/100"  << endl;
    cout << "Rage: 0/6" << endl;
    cout << "Bash: Damage = 30  Cost = 50 stamina  Effect: multiply damage by 1.5 and apply vulnerable." << endl;
    cout << "Slash: Damage = 20  Cost = 30 stamina  Effect: chance to critically strike for 2x damage or 1.2x damage." << endl;
    cout << "Vampiric: Damage = 18  Cost = 35 stamina  Effect: heal for damage dealt." << endl;
    cout << "Normal: Damage = 12  No Cost" << endl << endl;
    cout << "Do you wish to use this class? (Y/N)" << endl;
}
void characterCreationMenu(){                   //Prints menu for character creation and prompts user for a choice
    string choice;
        cout << "Berserker \t Scholar \t  Rogue" << endl;
        cout << "Select a class or Return for main menu" << endl;
        try{
            string job;
            cin >> job;
            job = lowercase(job);
            if(job != "return"){                            //if the player selection is not any of these words, throw exception and ask to select again
                if(job!="berserker"){
                    if(job!="scholar"){
                        if(job!="rogue"){
                            throw InvalidCharacterError();
                        }
                    }
                }
            }
                
            if(job == "return"){                            //return to main menu
                MainGameMenu();
            }
            else if(job == "berserker"){                    //select berserker with confirmation and ask for name 
                BerserkerSummary();
                cin >> choice;
                lowercase(choice);
                if(choice == "n"){
                    cout << "Select a different character" << endl;
                    characterCreationMenu();
                }
                else if(choice == "y"){
                    cout << "Please enter name. One word only." << endl;
                    cin >> playerName;

                    isBerserker = true;
                }
                else{
                    cout << "Invalid option! returning to character creation" << endl;                   //if neither yes or no, return to character creation menu
                    characterCreationMenu();
                }
            }
            else if(job == "scholar"){                    //select berserker with confirmation and ask for name 
                ScholarSummary();
                cin >> choice;
                lowercase(choice);
                if(choice == "n"){
                    cout << "Select a different character" << endl;
                    characterCreationMenu();
                }
                else if(choice == "y"){
                    cout << "Please enter name. One word only." << endl;
                    cin >> playerName;
                    isScholar = true;
                }
                else{
                    cout << "Invalid option! returning to character creation" << endl;                   //if neither yes or no, return to character creation menu
                    characterCreationMenu();
                }
            }
            else if(job == "rogue"){                    //select berserker with confirmation and ask for name 
                RogueSummary();
                cin >> choice;
                lowercase(choice);
                if(choice == "n"){
                    cout << "Select a different character" << endl;
                    characterCreationMenu();
                }
                else if(choice == "y"){
                    cout << "Please enter name. One word only." << endl;
                    cin >> playerName;
                    isRogue = true;
                }
                else{
                    cout << "Invalid option! returning to character creation" << endl;                   //if neither yes or no, return to character creation menu
                    characterCreationMenu();
                }
            }
        }
        catch(InvalidCharacterError){                                           //if player selects invalid class then return to character creation menu
            cout << "Not a valid class!" << endl;
            characterCreationMenu();
        }
    
}


void MenuLoad(){                                                        //Menu for when player selects load option
    try{                                                                //asks for which file to load, if it's not one of the available ones, throw exception and ask for file again
        cout << "File 1 \tFile 2 \tFile 3" << endl;
        cout << "Choose which file to load (Type 1, 2, or 3). Type Return for main menu." << endl;
        string option;
        cin >> option;
        lowercase(option);
        if(option != "return"){
            if(option != "1"){
                if(option != "2"){
                    if(option != "3"){
                        throw Not123Error();
                    }
                }
            }
        }
        if(option == "return"){                                          //return to main menu if wanted
            MainGameMenu();
        }
        else{
            option += ".txt";
            LoadFile = option;
        }
    }
    catch (Not123Error){
        cout << "Please choose 1, 2, or 3!" << endl;
        MenuLoad();
    }
}
void MainGameMenu(){                                    //The game's main menu; sets all variables to false, deletes player memory allocation; leads into other menus
    try{
        delete player;
        player = nullptr;
        isLoadMenu = false;
        isCharacterCreation = false;
        bool isBerserker = false;
        bool isRogue = false;
        bool isScholar = false;
        string LoadFile = "";
        cout  << setw(20) << "Kill The Tower" << endl;
        cout  << "Begin" << setw(20) << "Quit" << endl;
        string choice;
        cin >> choice;
        choice = lowercase(choice);
        if(choice != "begin"){
            if(choice != "quit"){
                throw InvalidActionError();
            }
        }
        if(choice == "begin"){                              //secondary menu; asks if new character or loading character
            cout << "New" << setw(22) << "Load" << endl;
            string option;
            cin >> option;
            option = lowercase(option);
            if(option != "new"){
                if(option != "load"){
                    throw InvalidActionError();
                }
            }
            if(option == "new"){
                characterCreationMenu();
                isCharacterCreation = true;
            }
            else if(option == "load"){
                MenuLoad();
                isLoadMenu = true;
            }
        }
        else if(choice == "quit"){                                              //exits the game
            GameLoop = false;
            cout << "The Tower is not kill" << endl;
            exit(0);
        }
    }
    catch(InvalidActionError){                                                  //exception for when player enters invalid options
        cout << "Invalid Option!" << endl;
        MainGameMenu();
    }
}

void GameVictory(){                                                              //Player victory, exits game
    cout << "The Tower is Kill." << endl;
    exit(0);
}

void InGameMenu(){                                                               //at the start of each floor
    cout << "Continue  Save  Return" << endl;
    cin >> inGameMenuChoice;
    lowercase(inGameMenuChoice);
    if(inGameMenuChoice == "return"){
        MainGameMenu();
    }
    else if(inGameMenuChoice == "save"){                                        //if player selects save in the pre battle menu, use the save function and print the menu again
        player->save();
        InGameMenu();
    }
}

#endif