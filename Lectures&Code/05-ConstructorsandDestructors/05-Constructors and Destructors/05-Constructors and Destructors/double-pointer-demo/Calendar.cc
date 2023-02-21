

#include "Calendar.h"

Calendar::Calendar(){
    dates[0] = new Date(2022);
    for (int i = 1; i < 365; ++i){
        dates[i] = new Date;
        dates[i]->setDate(*dates[i-1]); //Copy constructor
        dates[i]->incDate();
    }
}

//bool return type on the assignment
void Calendar::getDate(int index, Date** d){ //passing a pointer by refernce
    if (index < 0 || index > 365){ //Bounds check to make sure its valid
        *d = NULL;
        return;
    }

    *d = dates[index]; //Derefernce to get the pointer, assinging a date pointer to a date pointer
}