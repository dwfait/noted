#ifndef __FOLDER_COMMAND__H
#define __FOLDER_COMMAND__H

#include "command.h"

class FolderCommand : public Command
{
  public:
    FolderCommand();

    virtual void run();

  protected:
    virtual void setup_options();

};

#endif
