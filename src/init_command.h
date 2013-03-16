#ifndef __INIT_COMMAND__H
#define __INIT_COMMAND__H

#include "command.h"

class InitCommand : public Command
{
  public:
    InitCommand();

    virtual void run();

  protected:
    virtual void setup_options();
};

#endif
