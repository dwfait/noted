#include "folder_command.h"
#include <iostream>

#include <boost/filesystem.hpp>

#include "exceptions.h"
#include "repository.h"

namespace fs = boost::filesystem;

FolderCommand::FolderCommand()
  : Command("folder",
      "create and manage folders")
{}

void FolderCommand::run()
{
  Repository repo;

  if (vm.count("list") || additional_parameters.size() == 0)
  {
    repo.print_folder_list();
  }
  else
  {
    if (additional_parameters.size() != 1)
    {
      std::cout << "Uknown usage" << std::endl;
      return;
    }
    std::string folder_path = additional_parameters[0];

    if (vm.count("create")) {
      repo.create_folder(folder_path);
    } else if (vm.count("delete")) {
      repo.delete_folder(folder_path);
    } else {
      Folder dir = repo.get_folder(folder_path);
      dir.print_info();
    }
  }
}


void FolderCommand::setup_options()
{
  desc.add_options()
    ("help,h", "produce help message")
    ("create,c", "create a new folder")
    ("list,l", "create a new folder")
    ("delete,D", "delete a folder");
}
