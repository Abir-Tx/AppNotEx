#include <gtest/gtest.h>

#include <fstream>
#include <iostream>

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

  delete db;
  EXPECT_TRUE(status);
}

TEST(DatabaseTest, createDbTest) {
  const char *dbfilename = "../data/test/data.db";
  const char *tbname = "DataTest";
  Database *db = new Database();

  std::ifstream dbfile("../data/test/data.db");
  bool ok = false;
  if (!dbfile.is_open())
    ok = false;
  else
    ok = true;

  EXPECT_TRUE(ok);
}