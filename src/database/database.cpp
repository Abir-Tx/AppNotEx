#include "database.hpp"

#include <sqlite3.h>

#include <iostream>

// Macro for connecting to given database
#define CONNECT(dbname) \
  sqlite3 *datadb;      \
  int status = sqlite3_open(dbname, &datadb)

void Database::createDb(const char *dbname) {
  // Creating the database file
  CONNECT(dbname);

  //    checking for errors
  if (status == SQLITE_OK)
    std::cout << "Database Created Successfully" << std::endl;
  else
    std::cerr << "Error: " << sqlite3_errmsg(datadb);

  // Closing the database
  sqlite3_close(datadb);
}

void Database::createTable(const char *dbname, const char *tbname) {
  CONNECT(dbname);

  std::string tableName = tbname;
  std::string tbCreateQuery =
      "CREATE TABLE " + tableName + "(appname varchar(100));";
  sqlite3_exec(datadb, tbCreateQuery.c_str(), NULL, NULL, NULL);

  sqlite3_close(datadb);
}

void Database::insertData(const char *dbname, const char *tbname,
                          const char *appname) {
  CONNECT(dbname);

  std::string tableName = tbname;
  std::string appnameData = appname;
  std::string insertQuery = "INSERT INTO " + tableName + "(appname) VALUES(" +
                            "'" + appnameData + "'" + ");";
  sqlite3_exec(datadb, insertQuery.c_str(), NULL, NULL, NULL);
}