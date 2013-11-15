#ifndef GEOSRVSERVER_H_
#define GEOSRVSERVER_H_

#include "daework-include.h"
#include "daework-kernel.h"

class GeosrvServer  : public Server
{
        public:

                Dispatcher *dispatcherObject;

        public:
                GeosrvServer(const char *cfgFilePath, const char *env, const char *module):Server(cfgFilePath, env, module){};

                void init();
                Thread *createThreadObject();
                Dispatcher *createDispatcherObject();

};
#endif /* GEOSRVSERVER_H_ */
