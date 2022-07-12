#include <vector>
#include <iostream>
#include "PhoneBook.h"
#include "PhoneEntry.h"

//Retreive data from sql database
PhoneBook::PhoneBook() {

}
  vector<CourseEntry> PhoneBook::findBySchool(string school) {
    sql::Driver* driver = sql::mysql::get_driver_instance();
    std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
    con->setSchema(database);
    std::auto_ptr<sql::Statement> stmt(con->createStatement());

    vector<CourseEntry> list;
    stmt->execute("SELECT * FROM CurriculumMatchingExample WHERE SchoolName like '%"+school+"%'");
    std::auto_ptr< sql::ResultSet > res;
    do {
      res.reset(stmt->getResultSet());
      while (res->next()) {
          CourseEntry entry(res->getString("Subject"),res->getString("SchooName"),
			   res->getString("CourseName"),res->getString("Credits"),
	    res->getString("ID"));

	  list.push_back(entry);

      }
    } while (stmt->getMoreResults());
    return list;

}

vector<CourseEntry> PhoneBook::findBySubject(string subject) {
  sql::Driver* driver = sql::mysql::get_driver_instance();
  std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
  con->setSchema(database);
  std::auto_ptr<sql::Statement> stmt(con->createStatement());

  vector<CourseEntry> list;
  stmt->execute("SELECT * FROM CurriculumMatchingExample WHERE Subject like '%"+subject+"%'");
  std::auto_ptr< sql::ResultSet > res;
  do {
    res.reset(stmt->getResultSet());
    while (res->next()) {
      CourseEntry entry(res->getString("Subject"),res->getString("SchoolName"),
		       res->getString("CourseName"),res->getString("Credits"),
	res->getString("ID"));
        list.push_back(entry);

    }
  } while (stmt->getMoreResults());
  return list;

}
vector<CourseEntry> PhoneBook::findByCourse(string course) {
  sql::Driver* driver = sql::mysql::get_driver_instance();
  std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
  con->setSchema(database);
  std::auto_ptr<sql::Statement> stmt(con->createStatement());

  vector<CourseEntry> list;
  stmt->execute("SELECT * FROM CurriculumMatchingExample WHERE CourseName like '%"+course+"%'");
  std::auto_ptr< sql::ResultSet > res;
  do {
    res.reset(stmt->getResultSet());
    while (res->next()) {
      CourseEntry entry(res->getString("Subject"),res->getString("SchoolName"),
		       res->getString("CourseName"),res->getString("Credits"),
	res->getString("ID"));
      list.push_back(entry);

    }
  } while (stmt->getMoreResults());
  return list;

}
