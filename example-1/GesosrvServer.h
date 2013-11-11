#ifndef GESOSRVSERVER_H_
#define GESOSRVSERVER_H_

#include "daework-include.h"
#include "daework-kernel.h"

class GesosrvServer  : public Server
{
        public:

                Dispatcher *dispatcherObject;

        public:
                GesosrvServer(const char *cfgFilePath, const char *env, const char *module):Server(cfgFilePath, env, module){};

                void init();
                Thread *createThreadObject();
                Dispatcher *createDispatcherObject();

};
#endif /* GESOSRVSERVER_H_ */
