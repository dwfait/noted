#include "repository.h"
#include "exceptions.h"
#include "folder.h"

Repository::Repository()
{
  initialise();
}

fs::path Repository::get_path()
{
  return path;
}

void Repository::initialise()
{
  fs::path home_dir(getenv("HOME"));

  if (!fs::exists(home_dir))
    throw NotedException("Home directory doesn't exist!");

  fs::path noted_path = home_dir / "/noted";

  path = noted_path;

  if (!fs::exists(noted_path)) {
    if (!fs::create_directory(noted_path))
      throw NotedException("Couldn't create repository");
  }
}

void Repository::create_folder(std::string folder_name)
{
  fs::path new_folder_path = get_path() / folder_name;

  Folder new_folder(new_folder_path);

  new_folder.create();
}

void Repository::delete_folder(std::string folder_name)
{
  fs::path folder_to_delete_path = get_path() / folder_name;

  Folder folder_to_delete(folder_to_delete_path);

  folder_to_delete.destroy();
}

Folder Repository::get_folder(std::string folder_name)
{
  fs::path folder_path = get_path() / folder_name;

  return Folder(folder_path);
}

void Repository::print_folder_list()
{
  fs::directory_iterator it(path), end;

  for(; it != end; it++)
  {
    const fs::path& p = *it;
    if(fs::is_directory(p))
      std::cout << p.filename().string() << std::endl;
  }
}
