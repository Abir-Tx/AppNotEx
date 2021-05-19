#include "notex.hpp"

int main(int argc, char const *argv[]) {
  alib::clrscr();
  alib::decorateMe("Notex", 1, "", true);

  // Creating database & Table
  struct passwd *pw = getpwuid(getuid());

  const char *homedir = pw->pw_dir;
  std::string home = homedir;
  std::string dbfile = home + "/.local/share/data.db";
  const char *dbfilename = dbfile.c_str();
  const char *tbname = "general";
  Database *db = new Database();

  if (argc >= 2) {
    const char *availableCommands[] = {"-p", "--print"};

    if (std::strcmp(argv[1], availableCommands[0]) == 0 ||
        std::strcmp(argv[1], availableCommands[1]) ==
            0) { /* -p || --print option */
      db->printNotexData(dbfilename, tbname);
    } else {
      alib::horizontalLine(1, "red");
      std::cout << rang::fg::red << "Inavlid Arguments Passed"
                << rang::fg::reset << std::endl;
      alib::horizontalLine(1, "red");
    }
  } else {
    db->createDb(dbfilename);
    db->createNotexTable(dbfilename, tbname);
    std::string note;
    std::cout << "Extra Notes: ";
    getline(std::cin, note);
    bool queryStatus = db->insertNotexData(dbfilename, tbname, note.c_str());
    if (queryStatus)
      alib::decorateMe("Records kept successfully", 0, "*");
    else
      std::cerr << rang::fg::red << "Errors occured ! Couldn't store data"
                << rang::fg::reset << std::endl;
  }
  delete db;
  return 0;
}