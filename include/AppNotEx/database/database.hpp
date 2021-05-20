#if !defined(DATABASE_HPP)
#define DATABASE_HPP

// Includes
#include <pwd.h>
#include <sqlite3.h>
#include <sys/types.h>

#include <iostream>

#include "rang.hpp"
#include "spdlog/sinks/basic_file_sink.h"

// --------------------------------------Macros------------------------------------------
// Macro for const char*
#define COCHAR const char *
// Macro for connecting to given database
#define CONNECT(dbname) \
  sqlite3 *datadb;      \
  sqlite3_open(dbname, &datadb)

// -----------------------------------------DatabaseClass--------------------------------
class Database {
 private:
  static int callback(void *data, int argc, char **argv, char **azColName);

 public:
  void createDb(COCHAR dbname);
  void createTable(COCHAR dbname, COCHAR tbname);
  bool insertData(COCHAR dbname, COCHAR tbname, COCHAR appname,
                  COCHAR distroname, COCHAR link, COCHAR note);
  void printData(COCHAR dbname, COCHAR tbname);

  // notex methods
  void createNotexTable(COCHAR dbname, COCHAR tbname);
  bool insertNotexData(COCHAR dbname, COCHAR tbname, COCHAR note);
  void printNotexData(COCHAR dbname, COCHAR tbname);
};

#endif  // DATABASE_HPP
