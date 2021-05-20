#if !defined(EXPORT_HPP)
#define EXPORT_HPP

#include "../database/database.hpp"

class Export {
 public:
  void changeDbMode(COCHAR dbname);

  /* Save the export from appnotex using linux pipe */
  int pipeSave(const char *filename);
};

#endif  // EXPORT_HPP