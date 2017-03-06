			/**********************************************************************************
			 Title: College and University Data Analysis
			 Name: Shaswat Pratap Khan
			 Course: CSCI 501.01
			 Professor: Dr. Jordan Ringenberg
			 
			 Description:  This program provides the  systematic and structured information about the schools of three different states (Ohio, Miami  and Indiana). The information shared is about name of the schools,city, state, enrollment, tuition fee and type of the school(Private or Public). Along with it, average tuition fee of all schools from three states is calculated. Average enrollment of all the private schools from ohio is calculated and compared with "The University of Findlay".
			 Schools with highest, second highest and third highest tuition fees are enlisted along with their tuition fees.Schools from clevland with tuition fee more than $5000 and number of schools falling under this criteria is observed.
			 
			 Input:
			 Information about the schools is collected from the file "school_data.txt".The given file is to be read and the information about the schools from all the different states is fetched.
			 
			 
			 Output:  The following outputs will be printed to another file "school_output.txt " :
			 - Information of all the schools of three different states is listed.
			 - Average tuition for each state.
			 - Average enrollment for all the private Schools in Ohio.
			 - Comaparision of Average enrollment for all the private Schools in Ohio with enrollment of "The University of Findlay".
			 - Name and enrollment of the three schools with the highest tuitions overall.
			 - Schools and the tuition of the schools in Cleveland with the tuition fee above $5000 along with number of schools with this criteria.
			 
			 Special
			 details:  Entire data from the file is fetched .The output file is created and all the required data are printed in another file according to the desired design.Name of the school and its city, state, enrollment, tuition fee and type of the school are printed in one row using parallel array.
			 
			 **********************************************************************************/

			// Library Files
			# include <iostream>
			# include <fstream>
			# include <iomanip>
			# include <string>
			using namespace std;

			int main() {
				//Declaration of variables
				const int maxNumSchools=1000;         //maximum possible number of schools in the entire file "school_data.txt"
				string  names[maxNumSchools];         // name of the school
				string  cities[maxNumSchools];        // city of the school
				string  states[maxNumSchools];        // states of the school
				int     tuitions[maxNumSchools];      // tuition fee of the school
				int     enrollment[maxNumSchools];    // enrollment of the school
				string  types[maxNumSchools];         // type of the school(Public or Private)
				
				ifstream inFile;                      // inputstream file
				ofstream outFile;                     // outputStream file
				
				inFile.open("school_data.txt");       // school_data.txt file access to read the data
				outFile.open("school_output.txt");    // school_data.txt file access to write the data
				
				if( !inFile ){
					cout << "Unable to access the file "; // if file is not read
					return 1;
					
				}
				else{
					int numSchools = 0;                              // counter to iterate number of schools
					string temp;                                     // This variable stores the stateName temporarily
					bool checkAsterisks = false;                     // flag set to check asterisks in file
					
					int iterationForStates = 0;                      // iteration for the state
					int totalNumberOfStates = 3;                     // number of states( OH , MI, IN)
					int totalTuitionArray[totalNumberOfStates];      // total tuition per state
					int numberofSchoolsPerState = 0;                 // counter set for number of schools per state
					int tempForNumOfSchools;                         // stores number of schools per state
					int totalEnrollmentForOhio = 0;                  // counter set for total enrollment for ohio Schools
					int totalNumberOfPrivateSchoolInOhio = 0;        // counter to calculate the total number of private Schools in Ohio
					double avgEnrollmentOfPrivateSchoolsInOhio;      // Average enrollment of private Schools in Ohio
					double avgTuitionPerState[totalNumberOfStates];  // Average of the tuition fee per state is stored in each array
					int enrollmentForFindlay;                        // Enrollment for findlay
					int maxTuition = 0;                              // highest overall tuition
					int secondMaxTuition = 0;                        // second overall tuition
					int thirdMaxTuition  = 0;                        // third highest tuition
					int maxEnrollment ;                              // highest overall enrollment
					int secondMaxEnrollment ;                        // second overall enrollment
					int thirdMaxEnrollment  ;                        // third highest enrollment
					string maxTuitionCampus;                         // name of the school with highest tuition
					string secondMaxTuitionCampus;                   // name of the school with second highest tuition
					string thirdMaxTuitionCampus;                    // name of the school with third highest tuition
					string clevSchNames[25];                         // name of the school in Cleveland with tuition fee above $5000
					int clevSchCosts[25];                            // tuition fee of the school in Cleveland with tuition fee above $5000
					int clevSchCount = 0;                            // counter to find the number of schools in Cleveland with tuition fee above $5000
					
					
					
					//Reading the file and also checking the sentinels to switch state and end of file
					while( checkAsterisks == false && inFile >> temp ){
						inFile.ignore();
						bool checkPlus = false;                        // flag set to check +++ in the file
						if( temp != "***" ){
							int avgCount = 0;
							int totalTuitionForState = 0;                    // counter for total tuition per state
						   while( checkPlus == false && getline(inFile ,names[numSchools],'\n') && numSchools < maxNumSchools ){
							 if(names[numSchools] != "+++"){
							   getline(inFile,cities[numSchools],'\n');
							   inFile >> tuitions[numSchools] >> enrollment[numSchools];
							   states[numSchools] = temp;                                           //storing states for each school row
							   if(tuitions[numSchools] != -1){
								  totalTuitionForState = totalTuitionForState + tuitions[numSchools]; // total tuition for the state
								  avgCount++;
							   }
							  
							  inFile.ignore();
							  getline(inFile,types[numSchools],'\n');
							  
							  // calculating the total enrollment of the schools which is located in Ohio and is private
							  if( states[numSchools] == "OH" && types[numSchools] == "Private"){
								  totalEnrollmentForOhio = enrollment[numSchools] + totalEnrollmentForOhio;
								  totalNumberOfPrivateSchoolInOhio++;
								  
							  }
							  // enrollment of The University of Findlay
							  if(names[numSchools] == "The University of Findlay"){
								  enrollmentForFindlay=enrollment[numSchools];
							  }
							  // storing the name and tuition fee of the schools in Cleveland which have tuition fee above $5000.
							  if(cities[numSchools] == "Cleveland" && tuitions[numSchools] > 5000 && clevSchCount <= 25){
								  clevSchNames[clevSchCount] = names[numSchools];
								  clevSchCosts[clevSchCount] = tuitions[numSchools];
								  clevSchCount++;
							  }
							  numSchools++;
						  }
						  else{
							  checkPlus = true;
							  //calculation to find the average tuition of each states.
							  totalTuitionArray[iterationForStates] = totalTuitionForState;
							  tempForNumOfSchools = avgCount;
							  avgTuitionPerState[iterationForStates] = totalTuitionArray[iterationForStates] /(double) tempForNumOfSchools;
							  iterationForStates++;
							 // numberofSchoolsPerState = numSchools;
							  
						  }
					  }
						}
						else{
							checkAsterisks = true;
						}
					}
					//Displays information of all the schools of three different states in arranged manner
					outFile << "COLLEGE AND UNIVERSITY DATA ANALYSIS " << endl;
					outFile << "Task 1: " << endl;
					for( int i = 0; i < numSchools ; i++ ){
						outFile << setw(51) << left << names[i] << setw(25) << left << cities[i] << setw(4) << left << states[i] << setw(7) << right
								<< enrollment[i] << setw(7) << right << tuitions[i] << "  " << setw(9) << left << types[i] << "\n" ;
					}
					outFile << endl;
					outFile << endl;
					//Separates two different sections of output with 105 asterisks line and space lines
					for(int i = 0;i < 105; i++){
						outFile << "*";
					}
					outFile << endl;
					outFile << endl;
					//Displays the average tuition fee of schools from each state
					outFile <<  "Task 2:" << endl;
					outFile <<  "The average tuition fee of schools from Ohio state is $"    << fixed << setprecision(2) << avgTuitionPerState[0] << endl;
					outFile <<  "The average tuition fee of schools from Miami state is $"   <<  avgTuitionPerState[1] << endl;
					outFile <<  "The average tuition fee of schools from Indiana state is $" <<  avgTuitionPerState[2] << endl;
					outFile << endl;
					outFile << endl;
					for(int i = 0 ; i < 105; i++){
						outFile << "*";
					}
					outFile << endl;
					outFile << endl;
					//Displays the average enrollment of  private schools of Ohio state
					outFile << "Task 3: " << endl;
					avgEnrollmentOfPrivateSchoolsInOhio = totalEnrollmentForOhio / (double) totalNumberOfPrivateSchoolInOhio;
					outFile << "The average enrollment of private schools of Ohio state is "  << avgEnrollmentOfPrivateSchoolsInOhio << endl;
					outFile << "The enrollment of The University of Findlay is "  << enrollmentForFindlay << endl;
					outFile << endl;
					
					// Comparision of enrollment of Findlay with total enrollment of schools of Ohio state
					if(enrollmentForFindlay > totalEnrollmentForOhio){
						outFile << "Enrollment is higher in University of Findlay as compared to average of overall private OHIO Universities." << endl;
						
					}
					else if (enrollmentForFindlay < totalEnrollmentForOhio){
						outFile << "Enrollment is lower in University of Findlay as compared to average enrollment of overall private OHIO Universities." <<   endl;
					}
					else{
						outFile << "Enrollment of The University of Findlay is equal to the average enrollment of overall private OHIO Universities." << endl;
					}
					outFile << endl;
					outFile << endl;
					for(int i = 0 ; i < 105; i++){
						outFile << "*";
					}
					outFile << endl;
					outFile << endl;
					
					//swaping technique to find the highest three schools in terms of enrollment
					
					for( int j = 0; j < numSchools; j++ ){
						if( tuitions[j] > maxTuition ){
							secondMaxTuition = maxTuition;
							secondMaxTuitionCampus = maxTuitionCampus;
							maxTuition = tuitions[j];
							maxTuitionCampus = names[j];
							maxEnrollment = enrollment[j];
							
						}
						else if( tuitions[j] > secondMaxTuition ){
							thirdMaxTuition = secondMaxTuition;
							thirdMaxTuitionCampus  = secondMaxTuitionCampus;
							secondMaxTuition = tuitions[j];
							secondMaxTuitionCampus = names[j];
							secondMaxEnrollment = enrollment[j];
						}
						else if(tuitions[j] > thirdMaxTuition){
							thirdMaxTuition = tuitions[j];
							thirdMaxTuitionCampus = names[j];
							thirdMaxEnrollment= enrollment[j];
						}
					}
					//Displays the highest three schools in terms of enrollment
					outFile << "Task 4: " << endl;
					outFile << "Name of school with highest tuition is " << maxTuitionCampus << " with enrollment of " << maxEnrollment << endl;
					outFile << "Name of school with second highest tuition is " << secondMaxTuitionCampus << " with enrollment of " << secondMaxEnrollment <<   endl;
					outFile << "Name of school with third highest tuition is " << thirdMaxTuitionCampus << " with enrollment of " << thirdMaxEnrollment << endl;
					outFile << endl;
					outFile << endl;
					for(int i = 0; i < 105; i++){
						outFile << "*";
					}
					outFile << endl;
					outFile << endl;
					// Displays the name and tuition fee of the schools in Cleveland which have tuition fee above $5000.
					outFile << "Task 5: " << endl;
					outFile << "Schools in Cleveland with more than $5000 tuition fees: " << endl;
					outFile << endl;
					for( int k = 0; k < clevSchCount ; k++){
						outFile << clevSchNames[k] << " with tuition fee of $" << clevSchCosts[k] << endl;
						
					}
					// Displays number of schools in Cleveland which have tuition fee above $5000.
					outFile << endl;
					outFile << "The total number of school in Cleveland with tuition fee more than $5000 is " << clevSchCount << endl;
					outFile << endl;
					outFile << endl;
				}
				for(int i = 0; i < 105; i++){
					outFile << "*";
				}
				outFile << endl;
				outFile << endl;
				outFile.close(); // close of output file "school_output.txt"
				inFile.close();  // close of input file "school_data.txt"
				return 0;        // return an integer type value
			}



