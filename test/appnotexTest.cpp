#include <gtest/gtest.h>

#include <fstream>
#include <iostream>

#include "database.hpp"
#include "export/export.hpp"

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

TEST(DatabaseTest, fullLineTextTest) {
  // Creating database& Table
  const char *dbfilename = "../data/test/data.db";
  const char *tbname = "DataTest";
  Database *db = new Database();

  db->createDb(dbfilename);
  db->createTable(dbfilename, tbname);

  bool status = db->insertData(dbfilename, tbname, "mutt", "Arch",
                               "www.mutt.org", "Emailclient terminal based");

  delete db;
  EXPECT_TRUE(status);
}

TEST(DatabaseTest, createDbTest) {
  const char *dbfilename = "../data/test/data.db";
  Database *db = new Database();

  db->createDb(dbfilename);
  std::ifstream dbfile("../data/test/data.db");
  bool ok = false;
  if (!dbfile.is_open())
    ok = false;
  else
    ok = true;

  EXPECT_TRUE(ok);
}

// Appnotex Execution Tests
TEST(ExcutionTest, appnotex_print) {
  int status = system("./appnotex -p");
  EXPECT_EQ(status, 0);
}

TEST(ExcutionTest, appnotex_version) {
  int status = system("./appnotex -v");
  EXPECT_EQ(status, 0);
}

TEST(ExcutionTest, appnotex_help) {
  int status = system("./appnotex -h");
  EXPECT_EQ(status, 0);
}

/* TEST(ExportTest, appnotex_export) {
  Export *exptest = new Export();
  EXPECT_EQ(exptest->pipeSave("testExport"), 0);
} */

// Notex Tests
TEST(notexTest, insertQuerytest) {
  // Creating database& Table
  const char *dbfilename = "../data/test/data.db";
  const char *tbname = "generalTest";
  Database *db = new Database();

  db->createDb(dbfilename);
  db->createNotexTable(dbfilename, tbname);

  bool status = db->insertNotexData(dbfilename, tbname, "Hey Bro !");

  delete db;
  EXPECT_TRUE(status);
}