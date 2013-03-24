#include "command_dispatcher.h"
#include <iostream>
#include "exceptions.h"

int main(int argc, char** argv)
{
  CommandDispatcher dispatcher;

  try
  {
    dispatcher.dispatch(argc, argv);
  } catch (NotedException& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
