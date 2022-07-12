
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "PhoneBook.h"
#include "PhoneEntry.h"


using namespace std;

int main(){
    PhoneBook pb;
    vector<CourseEntry> pbResults;
    char o;

    cout << "Phone Book test program" << endl;

    cout << "Select an option (1-serach subject, 2-search school, 3-search course): ";
    cin >> o;

    while (o!='7') {
      if (o=='1') {
        cout << "Enter subject to find:";
        string subjectMatch;
        cin >> subjectMatch;

        pbResults = pb.findBySubject(subjectMatch);

        for (int i = 0; i<pbResults.size(); i++) {
        	cout << pbResults.at(i).ID << ". "
               << pbResults.at(i).subject << " "
        	     << pbResults.at(i).school << " "
        	     << pbResults.at(i).course << " "
        	     << pbResults.at(i).credits
        	     << endl;
        }
      } else if (o=='2') {

        cout << "Enter school to find:";
        string schoolMatch;
        cin >> schoolMatch;

        pbResults = pb.findBySchool(schoolMatch);

        for (int i = 0; i<pbResults.size(); i++) {
          cout << pbResults.at(i).ID << ". "
             << pbResults.at(i).subject << " "
        	   << pbResults.at(i).school << " "
        	   << pbResults.at(i).course << " "
        	   << pbResults.at(i).credits
        	   << endl;
        }
      } else if (o=='3') {
        cout << "Enter course to find:";
        string courseMatch;
        cin >> courseMatch;
        pbResults = pb.findByCourse(courseMatch);

        for (int i = 0; i<pbResults.size(); i++) {
          cout << pbResults.at(i).ID << ". "
          << pbResults.at(i).subject << " "
    	    << pbResults.at(i).school << " "
    	    << pbResults.at(i).course << " "
    	    << pbResults.at(i).credits
    	    << endl;
        }
      }
      cout << "Seect an option (1-serach subject, 2-search school, 3-search course): ";
      cin >> o;
    }
return 0;
}
