
#include "Board.h"

Board::Board(){
    reset();
}

void Board::reset(){
    for (int i = 0; i < BOARD_SIZE; ++i){
        positions[i] = ' ';
        red[i] = false;
    }
}

void Board::setCharacter(string avatar, int pos){
    for (int i = 0; i < avatar.size(); ++i){
        if (0 <= (pos + i) && (pos + i) < BOARD_SIZE){
            positions[pos+i] = avatar[i];
        }
    }
    
}

void Board::setRed(int pos){
    if (pos < 0 || pos >= BOARD_SIZE) return;
    red[pos] = true;
}



void Board::print() const{
    for (int i = 0; i < BOARD_SIZE; ++i){
        if (red[i]){
            cout<<"\033[31m"<<positions[i]<<"\033[0m";
        }else{
            cout<< positions[i];
        }
    }
}