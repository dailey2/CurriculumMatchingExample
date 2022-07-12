#include <string>
using namespace std;

#ifndef PHONEENTRY_H
#define PHONEENTRY_H

class CourseEntry {
public:
     CourseEntry();
     CourseEntry(string sub, string schl, string crs, string cred,string I);
     string subject;
     string school;
     string course;
     string credits;
     string ID;

private:

};

#endif /* PHONEENTRY_H */
