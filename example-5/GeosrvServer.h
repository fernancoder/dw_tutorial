#ifndef GEOSRVSERVER_H_
#define GEOSRVSERVER_H_

#include "daework-include.h"
#include "daework-kernel.h"
#include "daework-support.h"
#include "GeographicalInformator.h"

class GeosrvServer  : public Server
{
        public:
                Dispatcher *dispatcherObject;
                GeographicalInformator *geographicalInformator;

        public:
                GeosrvServer(const char *cfgFilePath, const char *env, const char *module):Server(cfgFilePath, env, module){};
                GeographicalInformator *getGeographicalInformator(){return geographicalInformator;};

                void init();
                Thread *createThreadObject();
                Dispatcher *createDispatcherObject();

};
#endif /* GEOSRVSERVER_H_ */
