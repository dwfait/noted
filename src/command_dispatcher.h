#ifndef __COMMAND_DISPATCHER__H
#define __COMMAND_DISPATCHER__H

#include "command.h"
#include <map>
#include <string>

typedef std::map<std::string, CommandPtr> CommandMap;

class CommandDispatcher
{
  public:
    CommandDispatcher();

    void dispatch(int argc, char** argv);

  private:
    //hashmap of commands:
    CommandMap commands;

    void add_command(CommandPtr command);

    std::string build_default_text();
    std::string available_commands_text();

};

#endif
