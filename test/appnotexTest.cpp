#include <gtest/gtest.h>

#include "database.hpp"

TEST(DatabaseTest, insertQueryTest) {
  // Creating database& Table
  const char *dbfilename = "../data/test/data.db";
  const char *tbname = "DataTest";
  Database *db = new Database();

  db->createDb(dbfilename);
  db->createTable(dbfilename, tbname);

  bool status = db->insertData(dbfilename, tbname, "mutt", "Arch",
                               "www.mutt.org", "Emailclient-terminal-based");

  EXPECT_TRUE(status);
}