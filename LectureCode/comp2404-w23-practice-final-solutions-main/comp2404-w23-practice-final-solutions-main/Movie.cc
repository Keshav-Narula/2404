#include "Movie.h"

//Implement stream insertion operator
ostream& operator<<(ostream& ost, const Movie& m){
    m.play(ost);
    return ost;
}
