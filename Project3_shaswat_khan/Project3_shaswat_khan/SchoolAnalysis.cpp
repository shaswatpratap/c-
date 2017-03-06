/**********************************************************************************
 Title: College and University Data Analysis Enhanced
 Name: Shaswat Pratap Khan
 Course: CSCI 501.01
 Professor: Dr. Jordan Ringenberg
 
 Description:  This program provides the  systematic and structured information 
 about the schools of different states . The information shared is about name 
 of the schools,city, state, enrollment, tuition fee and type of the school
 (Private or Public). In this program, the feature to add new schools in an
 array of object, sorting the object and searching the object is available.
 
 Input:
 -Information about the schools is collected from the files.The given file 
  is to be read and the information about the schools from all the different 
  states is fetched.
 -UserInput is required to choose the menu and which function is to be called.
 -While adding, new schools, details of the school should be provided.
 -While searching, input statename should be provided.
 
 Output:
 - Information of all the schools of states is listed.
 - New added schools are included along with the already existing schools.
 - Sorted List of schools
 - The list of the schools fromt the certain state is provided.

 Special
 details:  Entire data from the file is fetched . All the required data 
 are printed in console according to the desired design.Name of the 
 school and its city, state, enrollment, tuition fee and type of the
 school are printed in one row using object of a class School.
 
 **********************************************************************************/
// Library Function
#include "School.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Initializing functions
void readFile(ifstream &file, School schools[], int &numSchools);
void addSchools( int maxSize, School schools[], int &numSchools);
void sortSchools( School schools[], int &numSchools);
void searchSchools( School schools[], int &numSchools);
void printSchools( School schools[], int &numSchools);
int menu(int);
int main() {
    const int maxSize = 1000;
    ifstream inFile;
    School schools[maxSize];
    School school;
    int numSchools = 0;
    inFile.open("school_data2.txt");    // school_data.txt file access to read
    if( !inFile ){
        cout << "Unable to access the file "; // if file is not read
        return 1;
        
    }
    else{
        int entry;
        bool continueAgain = true;
        //Function to read the file
        readFile(inFile,schools , numSchools);
        while(continueAgain == true){
            //Menu Function
            int menuCommand = menu(entry);
            switch (menuCommand) {
                case 1:
                    //add  new schools
                    addSchools(maxSize, schools, numSchools);
                    printSchools(schools, numSchools);
                    continueAgain = true;
                    break;
                case 2:
                    // sort states and then its schools
                    sortSchools(schools, numSchools);
                    printSchools(schools, numSchools);
                    continueAgain = true;
                    break;
                case 3:
                    // searching the schools of particular state
                    sortSchools(schools, numSchools);
                    searchSchools(schools,numSchools);
                   // printSchools(schools, numSchools);
                    continueAgain = true;
                    break;
                case 4:
                    // print each schools in the list
                    printSchools(schools, numSchools);
                    continueAgain = true;
                    break;
                case 0:
                    // when userinput is 0
                    return 1;
                    break;
                default:
                    // when the userinput is invalid
                    cout << "Please enter valid option:: " << endl;
                    continueAgain = true;
                    break;
            }
        }

    }
return 0;
}
// Function to read the files
void readFile(ifstream &inFile,School schools[], int &numSchools){
    //Declaration of variables
    const int maxNumSchools=1000; //maximum possible number of schools
    string  names;         // name of the school
    string  cities;        // city of the school
    string  states;        // states of the school
    int     tuitions;      // tuition fee of the school
    int     enrollment;    // enrollment of the school
    string  types;         // type of the school(Public or Private)
    
    
    string temp;                // This variable stores the stateName temporarily
    bool checkAsterisks = false;  // flag set to check asterisks in file

    //Reading the file and also checking the sentinels to switch state and end of file
    while( checkAsterisks == false && inFile >> temp ){
        inFile.ignore();
        bool checkPlus = false;         // flag set to check +++ in the file
        if( temp != "***" ){
            while( checkPlus == false && getline(inFile ,names,'\n') && numSchools < maxNumSchools ){
                schools[numSchools].setSchoolName(names);
                if(names != "+++"){
                    getline(inFile,cities,'\n');
                    schools[numSchools].setCity((cities));
                    inFile >> tuitions >> enrollment;
                    schools[numSchools].setTuition(tuitions);
                    schools[numSchools].setEnrollment(enrollment);
                    schools[numSchools].setSchoolState(temp);
                    inFile.ignore();
                    getline(inFile,types,'\n');
                    schools[numSchools].setType(types);
                    numSchools++;
                }
                else{
                    checkPlus = true ;
                }
            }
        }
        else{
            checkAsterisks = true;
        }
    }

    }

//function to add new Schools
void addSchools( int maxSize, School schools[], int &numSchools){
    string name;
    string city;
    int    tuitions;
    int    enrollment;
    string type;
    string states;
    int a = 0;
    // check if the space is available in array and add 3 schools
    while(numSchools < maxSize && a < 3 ){
      {
        cout << "**********************************************************" << endl;
        cout << "Please enter details to add schools "<< endl;
        cout << "**********************************************************" << endl;
        cout << "Name of the Schools " << endl;
        getline(cin,name);
        cout << "Name of the state " << endl;
        cin  >> states;
        cin.ignore();
        cout << "Name of the city " << endl;
        getline(cin, city);
        cout << "Tuition cost of the school "<< endl;
        cin  >> tuitions;
        cout << "Enrollment of school "<< endl;
        cin  >> enrollment;
        cin.ignore();
        cout << "Type of school " << endl;
        getline(cin, type);
        schools[numSchools].setSchoolName(name);
        schools[numSchools].setSchoolState(states);
        schools[numSchools].setCity(city);
        schools[numSchools].setTuition(tuitions);
        schools[numSchools].setEnrollment(enrollment);
        schools[numSchools].setType(type);
        cout << "New School successfully addded in the list" << endl;
        numSchools++;
        a++;
    }
    if(numSchools > maxSize || a > 2){
        cout << "New School could not be added in the list" << endl;
        }
    }
    
}
/* function to sort the states and its schools 
   This function uses insertion sorting method
   At first, statename is sorted and then the list of
   Schools are sorted accordingly
 */
void sortSchools( School schools[], int &numSchools){
    int loc = 0;
    School key;
    for(int i = 1; i < numSchools ; i++)
    {
       key = schools[i];
       loc = i - 1;
       while(((loc >= 0)
             && (strcmp(schools[loc].getStateName().c_str(), key.getStateName().c_str()) > 0 ))
             ||((strcmp(schools[loc].getStateName().c_str(), key.getStateName().c_str()) == 0)
             &&(strcmp(schools[loc].getSchoolName().c_str(), key.getSchoolName().c_str()) > 0 ))
                ){
                schools[loc + 1]= schools[loc];
                loc--;
            }
            schools[loc + 1] = key;
        }

}

/* function to search the school list from a certain state 
   Binary search is used in order to achieve the search.
 */

void searchSchools( School schools[], int &numSchools){
    string target;
    int lowerLim = 0;
    int upperLim = numSchools - 1;
    bool found = false;
    int backLoopLimit;
    string search;
    int index = 0;
    cout << "\n Enter a state to search: ";
    cin  >> target;
    
    while(strcmp(schools[lowerLim].getStateName().c_str(),schools[upperLim].getStateName().c_str()) <= 0 && !found){
        index = (lowerLim + upperLim) / 2;
        if(schools[index].getStateName() < target){
            lowerLim = index + 1;
        }
        else if(schools[index].getStateName() > target){
            upperLim = index - 1;
        }
        else{
            found  = true;
            search = schools[index].getStateName();
        }
//            int j=1;
//            schools[j]=schools[index];
//            for(int i = index; i > 0 ; i-- ){
//                if(schools[i].getStateName() == schools[i-1].getStateName()){
//                    s=i-1;
//                    schools[j]=schools[s];
//                    j++;
//                }
//            for(int i = index; i < numSchools ; i++ ){
//                if(schools[i].getStateName()== schools[i+1].getStateName()){
//                    s=i+1;
//                    schools[j]=schools[s];
//                    j++;
//                }
//            }
//            }
//            
//                }
   }
    if(!found){
        cout << target << " is not in the list " << endl;
    }
    else{
        while(index > 0 && schools[index-1].getStateName() == search){
            index--;
        }
        backLoopLimit = index;
        while(backLoopLimit < numSchools && schools[backLoopLimit].getStateName() == search){
            schools[backLoopLimit].print();
            backLoopLimit++;
        }
    }
    
    cout << endl;

}
// print the schoollist
void printSchools( School schools[], int &numSchools){
    for(int i = 0  ; i < numSchools ; i++){
         schools[i].print();
    }
}
// function to call for userInput
int menu(int entry){
    cout << "**********************************************************" << endl;
    cout << "Menu:  " << endl;
    cout << "1. To add new Schools " << endl;
    cout << "2. To sort Schools " << endl;
    cout << "3. To search Schools from certain state " << endl;
    cout << "4. To print all the schools" << endl;
    cout << "0. To exit " << endl;
    cout << "**********************************************************" << endl;
    cout << "Please Enter the option(0-4): " << endl;
    cin  >> entry;
    cin.ignore();
    cout << "**********************************************************" << endl;
    return entry;
    
}
