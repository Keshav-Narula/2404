
#include "Battle.h"

using namespace std;

Battle::Battle(){
    ch.push_back(&orc);
    ch.push_back(&hero);
    ch.push_back(&wiz);
}

bool Battle::isOver() const{
    int players = ch.size();
    for(int i =0; i < ch.size(); ++i){
        if (ch[i]->isDead()){
            --players;
        }
    }

    return players <= 1;
}

void Battle::update(){

    board.reset();

    //hero and orc move and swing
    for (int i =0; i < ch.size(); ++i){
        if (ch[i]->isDead()){
            board.setRed(ch[i]->getPosition());
        } else {
            ch[i]->updatePosition();
            ch[i]->updateWeapon();
            //print their weapons on the board
            board.setCharacter(ch[i]->getSwing().weapon, ch[i]->getSwing().left);
        }
    }

    for (int i =0; i < ch.size(); ++i){
        //print the characters to the board
        board.setCharacter(ch[i]->getAvatar(), ch[i]->getPosition());
    }
    

    //check and see who hits who and set any character who was hit to red
    for (int i =0; i < ch.size(); ++i){
        for (int j =0; j < ch.size(); ++j){
            //we don't want characters to hit themselves
            if (i == j || ch[i]->isDead() || ch[j]->isDead()) continue;
            if (ch[i]->getHit(ch[j]->getSwing())){
                board.setRed(ch[i]->getPosition());
            }
        }
    }

    //print the characters or an X if they collide
    if (hero.getPosition() == orc.getPosition()){
        //they've collided
        board.setCharacter("X", hero.getPosition());
        board.setRed(hero.getPosition());
        hero.collide();
    }
    

    //print out the board and then character stats
    board.print();
    cout<<" || ";
    for (int i =0; i < ch.size(); ++i){
        ch[i]->print();
    }
    cout<<endl<<endl;;
}

void Battle::printResult() const {
    if (hero.isDead()){
        if (orc.isDead()){
            cout<<"Both are dead!!"<<endl;
        }else{
            cout<<"Orc is victorious!"<<endl;
        }
    }else{
        cout<<"Hero is victorious!"<<endl;
    }
}
