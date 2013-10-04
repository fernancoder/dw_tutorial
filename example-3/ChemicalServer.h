#ifndef CHEMICALSERVER_H_
#define CHEMICALSERVER_H_

#include "daework-include.h"
#include "daework-kernel.h"

class ChemicalServer  : public Server
{
  public:
    ChemicalServer(const char *cfgFilePath, const char *env, const char *module):Server(cfgFilePath, env, module){};

    void init();
    Thread *createThreadObject();
    Dispatcher *createDispatcherObject();

};
#endif /* CHEMICALSERVER_H_ */

