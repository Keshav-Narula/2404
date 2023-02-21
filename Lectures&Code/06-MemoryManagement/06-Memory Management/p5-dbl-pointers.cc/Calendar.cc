#include "Calendar.h"

Calendar::Calendar(){
    numDates = 0;
}

Calendar::~Calendar(){
    // Delete all Dates we are storing.
    // This will prevent memory leaks
    
}

bool Calendar::addDate(int y, int m, int d){
    if (numDates >= MAX_ARRAY) return false; //Check if calander is full first

    Date* date = new Date(y, m, d); //Date pointer pointing to a date object 

    int index = 0;
    //finds the right index for date
    while (index < numDates){ //
        if(date->lessThan(*dates[index])){
            break;
        }
        ++index;
    }

    //Loops from the back and adds date when the correct index is found

    // while(index > 0){
    //     if(dates[index-1]->lessThan(*date){
    //         break;
    //     }
    //     dates[index] = dates[index-1];
    //     --index;
    // }
    // dates[index] = date;
    // ++numdates;

    //Loops to add the element
    for (int i = numDates; i > index; --i){
        dates[i] = dates[i-1];
    }

    dates[index] = date;

    ++ numDates;
}

bool Calendar::removeDate(int y, int m, int d){
    Date date(y,m,d); //Make temporary date object and staticallly allocate it 

    //ITs possible for the date not ot eist, then dont do anything 
    int index = 0;
    //finds the right index for date
    while (index < numDates){
        if(date.equals(*dates[index])){ // Dereference since its a poitner then compare it to index
            break;
        }
        ++index;
    }
    //Didnt find object, then return failure
    if (index == numDates) return false;

    delete dates[index];
    //Copy stuff over to the left to maintain order
    while (index < numDates-1){
        dates[index] = dates[index+1];
        ++index;
    }
    --numDates;
}

bool Calendar::getDate(int index, Date** date){
    if (index < 0 || index >= numDates) return false; //That date is garbage 
    *date = dates[index]; //If not garabage data, dereference pointer and assign the value of the index
    return true;
}

void Calendar::print(){
    cout<<endl<<"Printing all dates: "<<endl;

    for (int i =0; i < numDates; ++i){
        dates[i]->print();
    }
    
}