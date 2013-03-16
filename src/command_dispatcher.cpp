#include "command_dispatcher.h"

#include "note_command.h"
#include "init_command.h"


#include <iostream>
#include <sstream>

CommandDispatcher::CommandDispatcher()
{
  CommandPtr note(new NoteCommand);
  CommandPtr init(new InitCommand);

  add_command(note);
  add_command(init);
}

void CommandDispatcher::add_command(CommandPtr command)
{
  commands[command->get_name()] = command;
}

void CommandDispatcher::dispatch(int argc, char** argv)
{
  if (argc <= 1)
  {
    std::cout << build_default_text();
    return;
  }

  std::string command_name(argv[1]);

  CommandMap::iterator command = commands.find(command_name);
  if (command != commands.end())
  {
    try
    {
      command->second->execute(argc, argv);
    } catch(po::error& e)
    {
      std::cout << e.what() << std::endl;
    }
  } else {
    std::cout << "Unknown command " << command_name << std::endl;
    std::cout << std::endl << available_commands_text();
  }
}

std::string CommandDispatcher::build_default_text()
{
  std::stringstream txt;

  txt << "Noted - a badly named note taking helper." << std::endl;
  txt << std::endl;

  txt << available_commands_text();

  return txt.str();
}

std::string CommandDispatcher::available_commands_text()
{
  std::stringstream txt;

  txt << "Available commands: " << std::endl;

  CommandMap::iterator it = commands.begin();

  for (; it != commands.end(); ++it)
  {
    txt << it->first << "\t" << it->second->get_description() << std::endl;
  }

  return txt.str();
}
