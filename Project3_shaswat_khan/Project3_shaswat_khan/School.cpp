
/* This file includes the setter and getter function. Also, the 
 constructor is set in this file.*/
 
// library function
#include "School.h"
#include  <string>
#include <iostream>
#include <iomanip>
using namespace std;


//Setting  the default constructor
School::School(){
    schoolName = "";
    state      = "";
    city       = "";
    tuition    = 0;
    enrollment = 0;
    type       = "";
    
}
// setting the constructor to initialise some values to the variable.
School :: School(string name, string stateName, string cityName,
                 int tuitionCost, int enrollmentVal, string typeCollege)
{
    
    schoolName = name;
    state      = stateName;
    city       = cityName;
    tuition    = tuitionCost;
    enrollment = enrollmentVal;
    type       = typeCollege;
}

void School::setSchoolName(string name){
    schoolName = name;
}

string School::getSchoolName(){
    return schoolName ;
}

void School::setCity(string cityName){
    city = cityName;
    
}
string School::getCity(){
    return city ;
}

void School::setSchoolState(string stateCode){
    state = stateCode;
}
string School::getStateName(){
    return state ;
}

void School::setTuition(int tuitionFee){
    tuition = tuitionFee;
}
int School::getTuition(){
    return tuition ;
}
void School::setEnrollment(int enrollmentNumber){
    enrollment = enrollmentNumber;
}
int School::getEnrollment(){
    return enrollment;
}

void School::setType(string typeOfSchool){
    type = typeOfSchool;
}
string School::getType(){
    return type;
}

void School::print(){
   cout << setw(56)<< left << schoolName << setw(25) <<
           left << city << setw(4) << left << state <<
           setw(7) << right << enrollment << setw(7)<< right
           << tuition << "  " << setw(9) << left << type << "\n" ;

}




