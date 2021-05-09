#include <gtest/gtest.h>

#include "database.hpp"

TEST(appnotexTest, insertQueryTest) {
  // Creating database& Table
  const char *dbfilename = "../data/data.db";
  const char *tbname = "Data";
  Database *db = new Database();

  bool status;
  status =
      db->insertData(dbfilename, tbname, "Gogle", "Test", "testme", "testme");

  EXPECT_TRUE(status);
}