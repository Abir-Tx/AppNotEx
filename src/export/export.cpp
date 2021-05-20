#include "export/export.hpp"

#include "errorcodes.hpp"

int Export::pipeSave(const char *filename) {
  std::string file = filename;
  std::string prepareCommand = "appnotex -p > " + file;
  const char *commandToExecute = prepareCommand.c_str();
  int status = system(commandToExecute);
  if (status == 0)
    return 0;
  else
    return CMDEXECFAILED;
}