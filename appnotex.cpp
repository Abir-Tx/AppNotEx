#include "alib.hpp"
#include "database.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
  // Displaying the title of the AppNotEx using Alib decorators
  alib::decorateMe("AppNotEx", 1, "", true);

  // Creating database
  const char *dbfilename = "../data/data.db";
  Database *db = new Database();
  db->createDb(dbfilename);

  return 0;
}
