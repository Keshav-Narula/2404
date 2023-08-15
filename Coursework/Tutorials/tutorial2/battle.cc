#include "battle.h"


void Gondor::fight(Character& fighter, Character& orc){
    orc.takeDamage(fighter.strike()+1);
    fighter.takeDamage(orc.strike()-1);

    cout<<endl<<"FIGHT IN GONDOR!"<<endl<<endl;

    cout<< fighter.getName() << " hits " <<orc.getName()<<" for "<< fighter.strike()+1<< " damage (BOOSTED in GONDOR)!"<<endl;
    cout<< orc.getName() << " hits " <<fighter.getName()<<" for "<< orc.strike()-1<< " damage!"<<endl;




}


void Mordor::fight(Character& fighter, Character& orc){

    orc.takeDamage(fighter.strike()-1);
    fighter.takeDamage(orc.strike()+1);

    cout<<endl<<"FIGHT IN MORDOR!"<<endl<<endl;


    cout<< fighter.getName() << " hits " <<orc.getName()<<" for "<< fighter.strike()-1<< " damage!"<<endl;
    cout<< orc.getName() << " hits " <<fighter.getName()<<" for "<< orc.strike()+1<< " damage (BOOSTED in MORDOR)!"<<endl;

    
}
