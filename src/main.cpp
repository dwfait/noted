#include "command_dispatcher.h"

int main(int argc, char** argv)
{
  CommandDispatcher dispatcher;

  dispatcher.dispatch(argc, argv);

  return 0;
}
