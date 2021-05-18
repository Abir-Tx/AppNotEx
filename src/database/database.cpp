#include "database.hpp"

#include <pwd.h>
#include <sqlite3.h>
#include <sys/types.h>

#include <iostream>

#include "rang.hpp"
#include "spdlog/sinks/basic_file_sink.h"

// Creating the logging object

struct passwd *pw = getpwuid(getuid());

const char *homedir = pw->pw_dir;
std::string home = homedir;
std::string logdir = home + "/.local/share/appnotexlog";

auto logger = spdlog::basic_logger_mt("appnotex", logdir);

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

// Function for printing Data from Database
int Database::callback(void *data, int argc, char **argv, char **azColName) {
  for (int i = 0; i < argc; i++) {
    // printing coloumn name and value
    std::cout << rang::style::bold << azColName[i] << ": " << rang::style::reset
              << argv[i] << std::endl;
  }
  std::cout << std::endl;
  return 0;
}

void Database::printData(COCHAR dbname, COCHAR tbname) {
  CONNECT(dbname);

  std::string tablename = tbname;
  std::string selectQuery =
      "SELECT appname AS 'App Name', distroname AS 'Distro Name', link AS 'App "
      "Link', note AS 'Extra Notes' FROM " +
      tablename + ";";

  int status = sqlite3_exec(datadb, selectQuery.c_str(), callback, NULL, NULL);

  if (status == SQLITE_OK)
    logger->info("Print data successfull");
  else
    logger->error("Could not read database & fetch data");

  sqlite3_close(datadb);
}

// notex methods
void Database::createNotexTable(COCHAR dbname, COCHAR tbname) {
  CONNECT(dbname);

  std::string tableName = tbname;
  std::string tbCreateQuery =
      "CREATE TABLE " + tableName + "(notes varchar(100));";

  sqlite3_exec(datadb, tbCreateQuery.c_str(), NULL, NULL, NULL);

  sqlite3_close(datadb);
}
bool Database::insertNotexData(COCHAR dbname, COCHAR tbname, COCHAR note) {
  CONNECT(dbname);

  std::string tableName = tbname;
  std::string noteData = note;
  std::string insertQuery =
      "INSERT INTO " + tableName + "(notes) VALUES(" + "'" + note + "'" + ");";
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

void Database::printNotexData(COCHAR dbname, COCHAR tbname) {
  CONNECT(dbname);

  std::string tablename = tbname;
  std::string selectQuery =
      "SELECT notes As 'Quick Notes' FROM " + tablename + ";";

  int status = sqlite3_exec(datadb, selectQuery.c_str(), callback, NULL, NULL);

  if (status == SQLITE_OK)
    logger->info("Print data successfull");
  else
    logger->error("Could not read database & fetch data");

  sqlite3_close(datadb);
}
