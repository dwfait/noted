#include "note_command.h"
#include <iostream>

NoteCommand::NoteCommand()
  : Command("note",
      "start a new note")
{}

void NoteCommand::run()
{
  if (vm.count("help")) {
    std::cout << desc << std::endl;
  }
}

void NoteCommand::setup_options()
{
  desc.add_options()
    ("help", "produce help message");
}
