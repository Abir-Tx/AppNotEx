#if !defined(DATABASE_HPP)
#define DATABASE_HPP

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
};

#endif  // DATABASE_HPP
