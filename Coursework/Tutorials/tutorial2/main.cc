#include "Character.h"
#include "battle.h"

int main(){
    string nameInput;
    int maxHealthInput;
    int damageInput;

    cout<<"PLEASE ENTER FIGHTER'S NAME, MAX HEALTH and DAMAGE"<<endl;
    cin>>nameInput>>maxHealthInput>>damageInput;

    Character fighter = Character(nameInput,maxHealthInput,damageInput);


    cout<<"PLEASE ENTER ORCS'S NAME, MAX HEALTH and DAMAGE"<<endl;
    cin>>nameInput>>maxHealthInput>>damageInput;

    Character orc = Character(nameInput,maxHealthInput,damageInput);

    cout<<endl;
    fighter.print();
    orc.print();

    Gondor::fight(fighter,orc);
    fighter.print();
    orc.print();


    Mordor::fight(fighter,orc);
    fighter.print();
    orc.print();

    return 0;
}