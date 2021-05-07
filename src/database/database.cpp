#include "database.hpp"

#include <sqlite3.h>

#include <iostream>

#include "spdlog/sinks/basic_file_sink.h"

// Macro for connecting to given database
#define CONNECT(dbname) \
  sqlite3 *datadb;      \
  int status = sqlite3_open(dbname, &datadb)

void Database::createDb(const char *dbname) {
  // Creating the database file
  CONNECT(dbname);

  // Creating the logging object
  auto logger = spdlog::basic_logger_mt("appnotex", "../data/appnotexlog");

  //    checking for errors
  if (status == SQLITE_OK)
    logger->info("Database Created Successfully");
  else {
    std::string errorMessage = sqlite3_errmsg(datadb);
    logger->info("Error: " + errorMessage);
  }

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