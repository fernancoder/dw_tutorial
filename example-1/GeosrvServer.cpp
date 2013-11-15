#include "GeosrvServer.h"
#include "GeosrvDispatcher.h"
#include "GeosrvThread.h"

void GeosrvServer::init()
{

}

Thread *GeosrvServer::createThreadObject()
{
        return (Thread *)(new GeosrvThread());
}

Dispatcher *GeosrvServer::createDispatcherObject()
{
        return (Dispatcher *)(new GeosrvDispatcher());
}
