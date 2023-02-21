
#include "Date.h"

class Calendar{

    public:
        Calendar();
        void getDate(int, Date**); //bool on the assinment to indicate failure or success

    private:
        Date* dates[365];
};