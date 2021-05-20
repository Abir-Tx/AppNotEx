#include <pwd.h>
#include <sys/types.h>

#include <fstream>
#include <string>

#include "alib.hpp"
#include "database.hpp"
#include "errorcodes.hpp"
#include "export/export.hpp"
#include "json/json.h"
#include "version.hpp"

int main(int argc, char const *argv[]) {
  // Getting the home directory
  struct passwd *pw = getpwuid(getuid());

  const char *homedir = pw->pw_dir;
  std::string home = homedir;

  // loading the configuration file
  std::string config_file = home + "/.config/appnotex/config.json";
  std::ifstream config(config_file);
  Json::Value root;
  config >> root;

  // ------------------------------------------------AppNotEx------------------------------------

  // Displaying the title of the AppNotEx using Alib decorators depending on the
  // user config. The default is to clear the screen first
  bool doClear = root.get("startupScreenClear", true).asBool();
  if (doClear) alib::clrscr();

  alib::decorateMe("AppNotEx", 1, "", true);

  // Creating database & Table
  std::string dbfile =
      home + root.get("dbsavedir", "/.local/share/data.db").asString();
  const char *dbfilename = dbfile.c_str();
  const char *tbname = "Data";
  Database *db = new Database();

  if (argc >= 2) {
    // If cmd line arguments are passed then do stuffs here
    const char *availableCmdArgs[] = {
        "-e", "--export",  "-p",         "--print", "-h",       "--help",
        "-g", "--general", "--printall", "-v",      "--version"};

    if (std::strcmp(argv[1], availableCmdArgs[0]) == 0 ||
        strcmp(argv[1], availableCmdArgs[1]) == 0) { /* --export || -e */

      Export *appnotexExport = new Export();

      int status = appnotexExport->pipeSave("appnotex-exported-data.txt");

      if (status == CMDEXECFAILED) {
        std::cerr << rang::fg::red << rang::style::bold
                  << "Error: Could not export and create data file"
                  << rang::fg::reset << rang::style::reset << std::endl;
      } else {
        std::cout << "The exported data have been saved as "
                  << rang::style::bold << "appnotex-exported-data.txt "
                  << rang::style::reset << "in the current directory"
                  << std::endl;
      }

    } else if (std::strcmp(argv[1], availableCmdArgs[2]) == 0 ||
               std::strcmp(argv[1], availableCmdArgs[3]) ==
                   0) { /* --print || -p */

      db->printData(dbfilename, tbname);

    } else if (std::strcmp(argv[1], availableCmdArgs[6]) == 0 ||
               std::strcmp(argv[1], availableCmdArgs[7]) ==
                   0) { /* -g || --general note taking || notex */
      system("./notex");
    } else if (std::strcmp(argv[1], availableCmdArgs[8]) ==
               0) { /* --printall */
      db->printData(dbfilename, tbname);
      alib::decorateMe("Notex", 1, "", true);
      db->printNotexData(dbfilename, "general");
      alib::horizontalLine(1, "blue");
    } else if (std::strcmp(argv[1], availableCmdArgs[9]) == 0 ||
               std::strcmp(argv[1], availableCmdArgs[10]) ==
                   0) { /* --version || -v */
      alib ::horizontalLine();
      std::cout << std::endl;
      std::cout << "Current appnotex version: " << appnotex::info::appnotexVer
                << std::endl;
      std::cout << "Developed By: " << developer << std::endl;
      std::cout << "License: " << license << std::endl;
      alib::horizontalLine();
    }

    else { /* Handle invalid or unsupported arguements and the help argument
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
    getline(std::cin, appnameData);
    std::cout << "Distro Name: ";
    getline(std::cin, distroname);
    std::cout << "App Link: ";
    getline(std::cin, link);
    std::cout << "Extra Notes: ";
    getline(std::cin, note);
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
