#include "database.hpp"

#include <sqlite3.h>

#include <iostream>

#include "spdlog/sinks/basic_file_sink.h"

// Creating the logging object
auto logger = spdlog::basic_logger_mt("appnotex", "../data/appnotexlog");

void Database::createDb(COCHAR dbname) {
  // Creating the database file
  sqlite3 *datadb;
  int status = sqlite3_open(dbname, &datadb);

  //    checking for errors
  if (status == SQLITE_OK) {
    logger->info("------------ New Session ----------");
    logger->info("Connected to Database Successfully");
  } else {
    std::string errorMessage = sqlite3_errmsg(datadb);
    logger->info("Error: " + errorMessage);
  }

  // Closing the database
  sqlite3_close(datadb);
}

void Database::createTable(COCHAR dbname, COCHAR tbname) {
  CONNECT(dbname);

  std::string tableName = tbname;
  std::string tbCreateQuery = "CREATE TABLE " + tableName +
                              "(appname varchar(100), distroname varchar(50), "
                              "link varchar(100), note varchar(100));";

  sqlite3_exec(datadb, tbCreateQuery.c_str(), NULL, NULL, NULL);

  sqlite3_close(datadb);
}

bool Database::insertData(COCHAR dbname, COCHAR tbname, COCHAR appname,
                          COCHAR distroname, COCHAR link, COCHAR note) {
  CONNECT(dbname);

  std::string tableName = tbname;
  std::string appnameData = appname;
  std::string insertQuery = "INSERT INTO " + tableName +
                            "(appname, distroname, link, note) VALUES(" + "'" +
                            appnameData + "'," + "'" + distroname + "'," + "'" +
                            link + "'," + "'" + note + "'" + ");";
  logger->info("Generated query to be executed: " + insertQuery);
  int queryStatus = sqlite3_exec(datadb, insertQuery.c_str(), NULL, NULL, NULL);
  if (queryStatus == SQLITE_OK) {
    logger->info("Data insertion in table -> " + tableName + " successfull");
    return true;
  } else {
    logger->critical("Data insertion failed unexpectedly");
    return false;
  }
}