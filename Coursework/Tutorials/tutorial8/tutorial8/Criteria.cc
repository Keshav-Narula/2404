#include "Criteria.h"

// cat_criteria
Cat_Criteria::Cat_Criteria(const string& categoryParam) : category(categoryParam) {
}

void Cat_Criteria::print(ostream& ost) const {
    ost << "CatCriteria Category: " << category<<endl;
}

bool Cat_Criteria::matches(const Photo& p) {
    if (p.getCategory() == category) {
        return true;
    } else {
        return false;
    }
}

// Date_Criteria

Date_Criteria::Date_Criteria(const Date& startDateParam, const Date& endDateParam) : start(startDateParam), end(endDateParam) {
}

void Date_Criteria::print(ostream& ost) const {
    ost << "Date_Criteria START Date: " << start << " END Date: " << end<<endl;;
}

bool Date_Criteria::matches(const Photo& p) {
    if (p.getDate() <= end && !(p.getDate() < start)) {
        return true;
    } else {
        return false;
    }
}

// CandD_Criteria

CandD_Criteria::CandD_Criteria(const Date& startDateParam, const Date& endDateParam, const string& categoryParam) : Date_Criteria(startDateParam, endDateParam), Cat_Criteria(categoryParam) {

}

void CandD_Criteria::print(ostream& ost) const {
    ost << "CandD_Criteria :" << endl;
    Cat_Criteria::print(ost);
    Date_Criteria::print(ost);
}

bool CandD_Criteria::matches(const Photo& p) {
    if(Date_Criteria::matches(p) && Cat_Criteria::matches(p)){
        return true;
    }else{
        return false;
    }
}
