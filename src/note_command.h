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

  private:
    std::string get_folder_name(std::string note_path);
    std::string get_note_name(std::string note_path);
};

#endif
