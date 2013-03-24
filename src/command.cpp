#include "command.h"

Command::Command(std::string name, std::string description)
  : desc(name),
  name(name), description(description)
{}

void Command::execute(int argc, char** argv)
{
  parse_options(argc, argv);

  if (vm.count("help")) {
    print_help_text();
  } else {
    run();
  }
}

void Command::parse_options(int argc, char** argv)
{
  setup_options();
  po::parsed_options parsed =
      po::command_line_parser(argc, argv).
      options(desc).
      allow_unregistered().
      run();

  po::store(parsed, vm);

  additional_parameters =
    po::collect_unrecognized(parsed.options,
        po::include_positional);

  //Remove the first element, which will be the command name:
  additional_parameters.erase(additional_parameters.begin());

  po::notify(vm);
}

std::string Command::get_name()
{
  return name;
}

std::string Command::get_description()
{
  return description;
}

void Command::print_help_text()
{
  std::cout << get_description() << std::endl;
  std::cout << desc << std::endl;
}
