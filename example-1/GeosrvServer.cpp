#include "GesosrvServer.h"
#include "GesosrvDispatcher.h"
#include "GesosrvThread.h"

void GesosrvServer::init()
{

}

Thread *GesosrvServer::createThreadObject()
{
        return (Thread *)(new GesosrvThread());
}

Dispatcher *GesosrvServer::createDispatcherObject()
{
        return (Dispatcher *)(new GesosrvDispatcher());
}
