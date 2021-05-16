#include <pwd.h>
#include <sys/types.h>

#include <iostream>
#include <string>

#include "alib.hpp"
#include "database.hpp"

int main(int argc, char const *argv[]) {
  // Displaying the title of the AppNotEx using Alib decorators
  alib::clrscr();
  alib::decorateMe("AppNotEx", 1, "", true);

  // Creating database & Table
  struct passwd *pw = getpwuid(getuid());

  const char *homedir = pw->pw_dir;
  std::string home = homedir;
  std::string dbfile = home + "/.local/share/data.db";
  const char *dbfilename = dbfile.c_str();
  const char *tbname = "Data";
  Database *db = new Database();

  if (argc >= 2) {
    // If cmd line arguments are passed then do stuffs here
    const char *availableCmdArgs[] = {"-e",      "--export", "-p",
                                      "--print", "-h",       "--help"};

    if (std::strcmp(argv[1], availableCmdArgs[0]) == 0 ||
        strcmp(argv[1], availableCmdArgs[1]) == 0) { /* --export || -e */

      std::cout << "\n[This feature will be soon available]";

    } else if (std::strcmp(argv[1], availableCmdArgs[2]) == 0 ||
               std::strcmp(argv[1], availableCmdArgs[3]) ==
                   0) { /* --print || -p */

      db->printData(dbfilename, tbname);

    } else { /* Handle invalid or unsupported arguements and the help argument
              */

      //  Show invalid arg notice if --help || -h is not given
      if (std::strcmp(argv[1], availableCmdArgs[4]) == 0 ||
          std::strcmp(argv[1], availableCmdArgs[5]) == 0) {
        std::cout << rang::bg::black << rang::style::underline
                  << rang::style::bold << " AppNotEx Help Menu \n\n"
                  << rang::bg::reset << rang::style::reset;
      } else {
        std::cout << "Invalid arguments passed. available commands are: ";
        std::cout << std::endl;
        std::cout << std::endl;
      }

      // Printing the available commands array
      std::cout << rang::style::italic << rang::fg::green
                << "AppNotEx commands: " << rang::style::reset
                << rang::fg::reset;
      for (int i = 0; i < sizeof availableCmdArgs / sizeof availableCmdArgs[0];
           i++) {
        std::cout << availableCmdArgs[i] << " ";
      }
    }
  } else {
    // if no cmd line arguments are passed then do stuffs here

    db->createDb(dbfilename);
    db->createTable(dbfilename, tbname);

    std::string appnameData, distroname, link, note;
    std::cout << "App Name: ";
    std::cin >> appnameData;
    std::cout << "Distro Name: ";
    std::cin >> distroname;
    std::cout << "App Link: ";
    std::cin >> link;
    std::cout << "Extra Notes: ";
    std::cin >> note;
    bool queryStatus =
        db->insertData(dbfilename, tbname, appnameData.c_str(),
                       distroname.c_str(), link.c_str(), note.c_str());
    if (queryStatus)
      alib::decorateMe("Records kept successfully", 0, "*");
    else
      std::cerr << rang::fg::red << "Errors occured ! Couldn't store data"
                << rang::fg::reset << std::endl;
  }

  // Free up the memory by deleting the Databse object
  delete db;
  return 0;
}
