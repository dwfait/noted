#ifndef __FOLDER__H
#define __FOLDER__H

#include <stdexcept>
#include <boost/filesystem.hpp>
#include "note.h"

namespace fs = boost::filesystem;

class Folder
{
  public:
    Folder(fs::path path);

    fs::path get_path();
    bool exists();

    void create();
    void destroy();

    void print_info();

    std::string folder_name();

    Note get_note(std::string note_name);

  private:
    fs::path path;
};

#endif
