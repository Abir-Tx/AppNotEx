#include "export/export.hpp"

#include <sqlite3.h>

#include <iostream>

void Export::changeDbMode(COCHAR dbname) { CONNECT(dbname); }