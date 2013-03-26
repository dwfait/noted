#include "note_command.h"
#include <iostream>
#include "exceptions.h"
#include "folder.h"
#include "note.h"
#include "repository.h"

NoteCommand::NoteCommand()
  : Command("note",
      "start a new note")
{}

void NoteCommand::run()
{
  if (additional_parameters.size() < 1)
  {
    std::cout << "unknown usage" << std::endl;
    return;
  }

  std::string note_path = additional_parameters[0];

  std::string folder_name = get_folder_name(note_path);
  std::string note_name   = get_note_name(note_path);


  Repository repo;
  Folder folder = repo.get_folder(folder_name);

  if (!folder.exists())
    throw NotedException("Folder "+folder_name+" does not exist");


  Note note = folder.get_note(note_name);

  if (vm.count("delete"))
  {
    note.destroy();
  } else if (vm.count("info")) {
    note.print_info();
  } else {

    if (!note.exists())
    {
      std::string note_title;
      if (additional_parameters.size() < 2)
      {
        note_title = note_name;
      } else {
        note_title = additional_parameters[1];
      }
      note.create(note_title);
    }

    std::string run_command("vim "+note.get_path().string());


    system(run_command.c_str());
  }
}

void NoteCommand::setup_options()
{
  desc.add_options()
    ("delete,D", "delete the note")
    ("info,i", "view information on this note")
    ("help,h", "produce help message");
}

std::string NoteCommand::get_folder_name(std::string note_path)
{
  size_t pos = note_path.find_first_of("/");
  size_t last_pos = note_path.find_last_of("/");

  if (pos == std::string::npos || pos == 0)
    throw NotedException("No folder specified");

  if (pos != last_pos)
    throw NotedException("You can not have nested folders");

  return note_path.substr(0, pos);
}

std::string NoteCommand::get_note_name(std::string note_path)
{
  size_t last_pos = note_path.find_last_of("/");

  return note_path.substr(last_pos+1);
}
