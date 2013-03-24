#include "note_command.h"
#include <iostream>

NoteCommand::NoteCommand()
  : Command("note",
      "start a new note")
{}

void NoteCommand::run()
{
  if (additional_parameters.size() != 2)
  {
    std::cout << "unknown usage" << std::endl;
    return;
  }

  std::string note_name = additional_parameters[0];
  std::string note_title = additional_parameters[1];

}

void NoteCommand::setup_options()
{
  desc.add_options()
    ("help,h", "produce help message");
}
