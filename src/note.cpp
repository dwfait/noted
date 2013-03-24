#include "note.h"
#include "exceptions.h"
#include <fstream>
#include <sstream>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_io.hpp>

Note::Note(fs::path path)
  : path(path.replace_extension(".markdown"))
{}

fs::path Note::get_path()
{
  return path;
}

bool Note::exists()
{
  return (fs::exists(path));
}

void Note::create(std::string note_title)
{
  if (exists())
    throw NotedException("Note already exists");

  std::string content = generate_initial_content(note_title);

  std::ofstream outfile(path.string().c_str());
  outfile << content << std::endl;
  outfile.close();
}

void Note::destroy()
{
  if (!exists())
    throw NotedException("Note doesn't exist");

  fs::remove_all(path);

  if (!exists())
  {
    std::cout << "Note deleted" << std::endl;
  } else {
    throw NotedException("Couldn't delete folder");
  }
}

void Note::print_info()
{
}

std::string Note::note_name()
{
  return (path.filename().string());
}


std::string Note::generate_initial_content(std::string note_title)
{
  std::stringstream str;

  str << "# " << note_title << std::endl;
  str << get_timestamp() << std::endl;

  return str.str();
}

std::string Note::get_timestamp()
{
  std::stringstream str;
  boost::posix_time::time_facet *facet = new boost::posix_time::time_facet("%d-%b-%Y");
  str.imbue(std::locale(str.getloc(), facet));
  str << boost::posix_time::second_clock::local_time() << std::endl;
  return str.str();
}
