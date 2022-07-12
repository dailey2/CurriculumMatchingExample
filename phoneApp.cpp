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

  if(operation=="Add Entry"){
    form_iterator afnameString = cgi.getElement("asubject");
    form_iterator alnameString = cgi.getElement("aschoolname");
    form_iterator addphoneString = cgi.getElement("acoursename");
    form_iterator addtypeString = cgi.getElement("acredits");

    string addsubject=**asubjectString;
    string addschoolname=**aschoolnameString;
    string addcoursename=**addcoursenameString;
    string addcredits=**addcreditsString;

    pb.addEntry(addsubject,addschoolname,addcoursename,addcredits);
    output="success";
  }

  if(operation=="delete"){
    form_iterator idtodeleteString = cgi.getElement("deleteid");
    string iddelete=**idtodeleteString;

    pb.deleteEntry(iddelete);
    output="success";
  }
  if(operation=="edit"){
    form_iterator idtoeditString = cgi.getElement("editid");
    string idedit=**idtoeditString;

    form_iterator editsubjectString = cgi.getElement("editfname");
    form_iterator editschoolnameString = cgi.getElement("editlname");
    form_iterator editcoursenameString = cgi.getElement("editphone");
    form_iterator editcreditsString = cgi.getElement("edittype");

    string editsubject=**editsubjectString;
    string editschoolname=**editschoolnameString;
    string editcoursename=**editcoursenameString;
    string editcredits=**editcreditsString;


    pb.editEntry(idedit,editsubject,editschoolname,editcoursename,editcredits);
    output="success";
  }

  /* send back the results */
  cout << "Content-Type: text/plain\n\n";

  cout << output << endl;


  return 0;
}
