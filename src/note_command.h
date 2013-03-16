#ifndef __NOTE_COMMAND__H
#define __NOTE_COMMAND__H

#include "command.h"

class NoteCommand : public Command
{
  public:
    NoteCommand();

    virtual void run();

  protected:
    virtual void setup_options();
};

#endif
