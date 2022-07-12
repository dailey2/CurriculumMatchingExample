#include <iostream>
#include <fstream>
#include <string>
#include <map>

// Stuff for AJAX
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include "PhoneBook.h"
#include "PhoneEntry.h"

#define XML_USE_STL

using namespace std;
using namespace cgicc; // Needed for AJAX functions.

ofstream logfile;

int main() {
  Cgicc cgi;    // Ajax object
  char *cstr;

  PhoneBook pb; // Phone Book SQL Interface Object
  vector<CourseEntry> pbResults;

  // Create AJAX objects to recieve information from web page.
  form_iterator op = cgi.getElement("operation");
  string operation = **op;
  logfile.open("/home/fifo/skonphone.log",ios::out | ios::app);
  logfile << "Op:" << operation << endl;
  logfile.close();
  string output = "Error = "+operation+ " - Operation not support yet!";
  if (operation == "Find Subject") {
    form_iterator searchString = cgi.getElement("find");
    string search = **searchString;

    pbResults = pb.findBySubject(search);
    if (pbResults.size() > 0) {
      output = "success";
      for (int i = 0; i<pbResults.size(); i++) {
	output += "," + pbResults.at(i).subject + ","
	  + pbResults.at(i).school + ","
	  + pbResults.at(i).course + ","
	  + pbResults.at(i).credits + ","
	  + pbResults.at(i).ID;
      }
    } else {
      output = "No Match Found";
    }
  }

  if (operation == "Find School") {
    form_iterator searchString = cgi.getElement("find");
    string search = **searchString;

    pbResults = pb.findBySchool(search);
    if (pbResults.size() > 0) {
      output = "success";
      for (int i = 0; i<pbResults.size(); i++) {
	output += "," + pbResults.at(i).subject + ","
	  + pbResults.at(i).school + ","
	  + pbResults.at(i).course + ","
	  + pbResults.at(i).credits + ","
	  + pbResults.at(i).ID;
      }
    } else {
      output = "No Match Found";
    }
  }
  if (operation == "Find Course") {
    form_iterator searchString = cgi.getElement("find");
    string search = **searchString;

    pbResults = pb.findByCourse(search);
    if (pbResults.size() > 0) {
      output = "success";
      for (int i = 0; i<pbResults.size(); i++) {
	output += "," + pbResults.at(i).subject + ","
	  + pbResults.at(i).school + ","
	  + pbResults.at(i).course + ","
	  + pbResults.at(i).credits + ","
	  + pbResults.at(i).ID;
      }
    } else {
      output = "No Match Found";
    }
  }

  /* send back the results */
  cout << "Content-Type: text/plain\n\n";

  cout << output << endl;


  return 0;
}
