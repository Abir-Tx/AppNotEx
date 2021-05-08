#if !defined(EXPORT_HPP)
#define EXPORT_HPP

#include "../database/database.hpp"

class Export {
 public:
  void changeDbMode(COCHAR dbname);
};

#endif  // EXPORT_HPP