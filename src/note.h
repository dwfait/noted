#ifndef __NOTE__H
#define __NOTE__H

#include <stdexcept>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

class Note
{
  public:
    Note(fs::path path);

    fs::path get_path();
    bool exists();

    void create(std::string note_title);
    void destroy();

    void print_info();

    std::string note_name();

  private:
    fs::path path;

    std::string generate_initial_content(std::string note_title);

    std::string get_timestamp();
};

#endif
