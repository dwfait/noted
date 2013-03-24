#ifndef __COMMAND__H
#define __COMMAND__H

#include <string>
#include "boost/shared_ptr.hpp"
#include "boost/program_options.hpp"

namespace po = boost::program_options;

class Command
{
  public:
    Command(std::string name, std::string description);
    virtual ~Command() {}

    void execute(int argc, char** argv);

    std::string get_name();
    std::string get_description();

  protected:
    virtual void run() = 0;
    virtual void setup_options() = 0;

    po::options_description desc;
    po::variables_map vm;
    std::vector<std::string> additional_parameters;

  private:
    void parse_options(int argc, char** argv);
    void print_help_text();

    std::string name;
    std::string description;
};

typedef boost::shared_ptr<Command> CommandPtr;

#endif
