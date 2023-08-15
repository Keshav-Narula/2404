#include <iostream>
#include <string>
#include "Battle.h"
#include <time.h>
#include <cstdlib>


using namespace std;

int random(int);

int main(){

    srand (time(NULL));

    Battle battle;

    // the game loop
    while(!battle.isOver()){
        battle.update();
    }

    battle.printResult();
    
    return 0;
}

int random(int num){
    return rand() % num;
}