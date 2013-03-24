#ifndef __REPOSITORY__H
#define __REPOSITORY__H

#include <stdexcept>
#include <boost/filesystem.hpp>
#include "folder.h"

namespace fs = boost::filesystem;

class Repository
{
  public:
    Repository();
    fs::path get_path();

    void create_folder(std::string folder);
    void delete_folder(std::string folder);
    Folder get_folder(std::string folder);

    void print_folder_list();

  private:
    void initialise();

    fs::path path;

};

#endif
