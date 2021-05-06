#include "database.hpp"
#include <iostream>
#include <sqlite3.h>

void Database::createDb(const char *dbname) {
  sqlite3 *datadb;

  // Creating the database file
  int status = sqlite3_open(dbname, &datadb);

  //    checking for errors
  if (status == SQLITE_OK)
    std::cout << "Database Created Successfully" << std::endl;
  else
    std::cerr << "Error: " << sqlite3_errmsg(datadb);

  // Closing the database
  sqlite3_close(datadb);
}