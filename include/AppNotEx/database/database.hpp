#if !defined(DATABASE_HPP)
#define DATABASE_HPP

class Database {
 private:
 public:
  void createDb(const char *dbname);
  void createTable(const char *dbname, const char *tbname);
  void insertData(const char *dbname, const char *tbname, const char *appname);
};

#endif  // DATABASE_HPP
