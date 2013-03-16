#include "init_command.h"
#include <iostream>

InitCommand::InitCommand()
  : Command("init",
      "initialise the note repository")
{}

void InitCommand::run()
{
  if (vm.count("help")) {
    std::cout << desc << std::endl;
  }
}

void InitCommand::setup_options()
{
  desc.add_options()
    ("help", "produce help message");
}
