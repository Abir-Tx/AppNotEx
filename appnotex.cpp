#include <iostream>

#include "alib.hpp"
#include "database.hpp"

int main(int argc, char const *argv[]) {
  // Displaying the title of the AppNotEx using Alib decorators
  alib::clrscr();
  alib::decorateMe("AppNotEx", 1, "", true);

  if (argc >= 2) {
    // If cmd line arguments are passed then do stuffs here
    const char *availableCmdArgs[] = {"-e", "--export"};

    if (std::strcmp(argv[1], availableCmdArgs[0]) == 0 ||
        strcmp(argv[1], availableCmdArgs[1]) == 0) {
      std::cout << "\n[This feature will be soon available]";
    } else {
      std::cout << "Invalid arguments passed. available commands are";
      std::cout << std::endl;
    }
  } else {
    // if no cmd line arguments are passed then do stuffs here

    // Creating database & Table
    const char *dbfilename = "../data/data.db";
    const char *tbname = "Data";
    Database *db = new Database();
    db->createDb(dbfilename);
    db->createTable(dbfilename, tbname);

    std::string appnameData, distroname, link, note;
    std::cout << "Enter the app name data: ";
    std::cin >> appnameData;
    std::cout << "Enter the distroname: ";
    std::cin >> distroname;
    std::cout << "Enter the link of the app: ";
    std::cin >> link;
    std::cout << "Enter additional notes: ";
    std::cin >> note;
    bool queryStatus =
        db->insertData(dbfilename, tbname, appnameData.c_str(),
                       distroname.c_str(), link.c_str(), note.c_str());
    if (queryStatus)
      alib::decorateMe("Records kept successfully", 0, "*");
    else
      std::cerr << rang::fg::red << "Errors occured ! Couldn't store data"
                << rang::fg::reset << std::endl;
    delete db;
  }
  return 0;
}
