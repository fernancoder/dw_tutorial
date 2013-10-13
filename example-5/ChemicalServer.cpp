#include "ChemicalServer.h"
#include "ChemicalDispatcher.h"
#include "ChemicalThread.h"

void ChemicalServer::init()
{

}

Thread *ChemicalServer::createThreadObject()
{
  return (Thread *)(new ChemicalThread());
}

Dispatcher *ChemicalServer::createDispatcherObject()
{
  return (Dispatcher *)(new ChemicalDispatcher());
}

