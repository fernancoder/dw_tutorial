#include "daework-kernel.h"
#include "ChemicalServer.h"

int main (int argc, char **argv)
{
  ChemicalServer *server = new ChemicalServer("./chemical.ini", "pro", "main");
  Daemonizer::daemonize(server, true);

  return 0;
}

