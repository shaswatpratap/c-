/*
 Project: Lab3 mistake
 Title: City Populations, Redesigned
 Name: Shaswat Pratap Khan
 Date: 21 February 2017
 Professor: Dr. Jordan Ringenberg
 
 Description: This program provides the information about the city and its population mentioned in a file. As per the user input the population bar chart is    designed.
 
 Inputs:
 - Input file is read "POP. txt"
 - New city information added in an array.
 - How many asterisks per population is needed.
 
 Outputs:
 - Information of the city arranged albhapetically along with its population.
 
 special - Struct is used in inorder to store the city information in an array. Use of Function can also be observed in the given program. Use Function is capable of performing tasks like read the file, store the information and print the output.
 */


//Library files

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


// Use of struct to store information
struct City{
    string names;
    int population;
    
};

// function to read the file information
void readCities( ifstream &, City[] , int & );
// function to print the file information
void printPopulations(City [],int &);
int main() {
    int numCities=0;
    const int maxNumofCities=30;
    City city[maxNumofCities];
    
    ifstream inFile;
    inFile.open("POP.txt");
    
    
    if(!inFile){
        cout << "No access to File";
        
    }
    else{
        readCities( inFile, city, numCities);
        printPopulations(city,numCities);
        
    }
    
    return 0;
    
}
void readCities(ifstream &inFile, City city[],int &numCities ){
    const int maxNumofCities = 30;
    string sortedArr[maxNumofCities];
    int popnArr[maxNumofCities];
    int numItems = 0;
    string nameOfCity ;
    bool added = false;
    string temp;
    int tempPop;
    int pop;
    
    while(inFile.peek() !=EOF){
        getline(inFile,city[numCities].names);
        inFile >> city[numCities].population;
        inFile.ignore();
        numCities++;
        
        added = false;
        //could do this way for adding at end of array
        
        if (((numItems == 0 || (city[numCities].names).compare(city[numCities-1].names)==0 || (city[numCities].names).compare(city[numCities-1].names)>0))){
            sortedArr[numItems] = city[numItems].names;
            popnArr[numItems] = city[numItems].population;
            numItems++;
        }
        else {
            for ( int i = 0; i < numItems && added == false; i++) {
                //find where it needs to go
                if (sortedArr[i].compare(city[numItems].names) >0 ) {
                    //bump elements down to make room
                    for (int j = numItems; j > i; j--) {
                        sortedArr[j] = sortedArr[j - 1];
                        popnArr[j]=popnArr[j-1];
                    }
                    //put the item into the array
                    sortedArr[i] = city[numItems].names;
                    popnArr[i] = city[numItems].population;
                    //Mark that an item was added
                    numItems++;
                    added = true;
                }
            }
        }
    }
    for (int i = 0; i < numItems; i++) {
        city[i].names= sortedArr[i];
        city[i].population=popnArr[i];
        
    }
    // cout << i;
    cout << endl;
    
    
}

//    while(inFile.peek() !=EOF){
//        getline(inFile,city[numCities].names);
//        inFile >> city[numCities].population;
//        inFile.ignore();
//        numCities++;
//    }
////    for( int l=0; l < 5; l++){
////        int j=1;
////        city[numCities+j].names=sortedArr[l];
////        city[numCities+j].population=popnArr[l];
////        numCities++;
////        j++;
////
////    }
//    //cout << numCities;
//    for(int a = 0; a < numCities; a++){
//        for(int c = 0;c < numCities-a ;c++){
//            if(strcmp(city[c].names.c_str(), city[c+1].names.c_str())>0){
//                for(int n = 0;n < numCities;n++){
//                    for(int k = n+1;k < numCities; k++){
//                        if(strcmp(city[n].names.c_str(), city[k].names.c_str())>0){
//                            temp = city[n].names;
//                            tempPop = city[n].population;
//                            city[n].names=city[k].names;
//                            city[n].population = city[k].population;
//                            city[k].names = temp;
//                            city[k].population = tempPop;
//
//                        }
//                    }
//                }
//            }
//        }
//    }


//    while(inFile.peek() !=EOF){
//        getline(inFile,city[numCities].names);
//        inFile >> city[numCities].population;
//        inFile.ignore();
//        numCities++;
//    }
//}
void printPopulations(City city[],int &numCities){
    int chart;
    int asteriskValue;
    int highestPop = 0;
    int secondHighestPop = 0;
    string highestPopCity;
    string secondHighestPopCity;
    
    cout << "How many asterisks per people" << endl;
    cin >> asteriskValue;
    for(int j = 0;j < numCities; j++){
        chart = city[j].population/asteriskValue;
        cout << setw(14) << left << city[j].names << "" ;
        for(int i = 0; i < chart ; i++){
            cout <<  " *" ;
        }
        cout << endl ;
        // sorting to find the highest population city and its population
        if(city[j].population > highestPop){
            secondHighestPop = highestPop;
            secondHighestPopCity = highestPopCity;
            highestPopCity = city[j].names;
            highestPop = city[j].population;
        }
        else if(city[j].population > secondHighestPop){
            secondHighestPop = city[j].population;
            secondHighestPopCity = city[j].names;
        }
        
        
        
    }
    // display the highest and second highest populated cities with their population
    cout << "The highest population is in " << highestPopCity << " with population of " << highestPop << endl;
    cout << "The second highest population is in " << secondHighestPopCity << " with population of " << secondHighestPop << endl;
}
