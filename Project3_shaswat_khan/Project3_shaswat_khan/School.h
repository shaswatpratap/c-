
/* This file is defined as the header file where class name and
   the its variabless and functions are defined.
 */

#ifndef School_h
#define School_h
#include <string>
using namespace std;


class School{
// Instances are declared as private so in order to protect it from direct use.
private:
    string schoolName;
    string state;
    string city;
    int tuition;
    int enrollment;
    string type;

public:
    /* methods are declared as public and hence any other file can also have 
     access over the methods. The value is assigned to the instance through 
     these methods. */
    School();
    School(string schoolName, string state, string city, int tuition,
            int enrollment, string type);
    
    void   setSchoolName(string name);
    string getSchoolName();
    void   setSchoolState(string state);
    string getStateName();
    void   setCity(string city);
    string getCity();
    void   setTuition(int tuition);
    int    getTuition();
    void   setEnrollment(int enrollment);
    int    getEnrollment();
    void   setType(string type);
    string getType();
    void   print();
};

#endif /* School_h */
