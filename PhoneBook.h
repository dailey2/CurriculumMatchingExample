#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
/* uncomment for applications that use vectors */
#include <vector>

#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "PhoneEntry.h"

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#define HOST "localhost"
#define USER "dailey2"
#define DB "CurriculumMatchingExample"
#define PASS "S220199"

using namespace std;

class PhoneBook {
public:
    PhoneBook();
    vector<CourseEntry> findBySubject(string subject);
    vector<CourseEntry> findBySchool(string school);
    vector<CourseEntry> findByCourse(string course);

private:
    const string url=HOST;
    const string user=USER;
    const string database=DB;
    const string pass=PASS;

};

#endif /* PHONEBOOK_H */
