#ifndef __EXCEPTIONS__H
#define __EXCEPTIONS__H

#include <stdexcept>

class NotedException : public std::runtime_error
{
  public:
    NotedException(const std::string& msg)
      : std::runtime_error(msg)
    {}
};

#endif
