#if !defined(DATABASE_HPP)
#define DATABASE_HPP

class Database {
private:
public:
  void createDb(const char *dbname);
  void createTable(const char *dbname, const char *tbname);
};

#endif // DATABASE_HPP
