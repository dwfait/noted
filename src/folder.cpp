#include "folder.h"
#include "exceptions.h"

Folder::Folder(fs::path path)
  : path(path)
{}

fs::path Folder::get_path()
{
  return path;
}

bool Folder::exists()
{
  return (fs::exists(path));
}

void Folder::create()
{
  if (exists())
    throw NotedException("Folder already exists");

  if (!fs::create_directory(path))
  {
    throw NotedException("couldn't create new folder");
  } else {
    std::cout << "Folder created" << std::endl;
  }
}

void Folder::destroy()
{
  if (!exists())
    throw NotedException("Folder doesn't exist");

  fs::remove_all(path);

  if (!exists())
  {
    std::cout << "Folder deleted" << std::endl;
  } else {
    throw NotedException("Couldn't delete folder");
  }
}

void Folder::print_info()
{
  if (exists())
  {
    std::cout << folder_name() << " exists. To do: print info." << std::endl;
  } else {
    std::cout << folder_name() << " doesn't exist yet. Use --create to create it." << std::endl;
  }
}

std::string Folder::folder_name()
{
  return (path.filename().string());
}

Note Folder::get_note(std::string note_name)
{
  return Note(path / note_name);
}
