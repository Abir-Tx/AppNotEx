#include <iostream>

#include "alib.hpp"
#include "database.hpp"

int main(int argc, char const *argv[]) {
  // Displaying the title of the AppNotEx using Alib decorators
  alib::decorateMe("AppNotEx", 1, "", true);

  // Creating database & Table
  const char *dbfilename = "../data/data.db";
  const char *tbname = "Data";
  Database *db = new Database();
  db->createDb(dbfilename);
  db->createTable(dbfilename, tbname);

  std::string appnameData;
  std::cout << "Enter the app name data: ";
  std::cin >> appnameData;
  db->insertData(dbfilename, tbname, appnameData.c_str());
  delete db;
  return 0;
}
