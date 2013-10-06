#ifndef CHEMICALDISPATCHER_H_
#define CHEMICALDISPATCHER_H_

#include "daework-kernel.h"

class ChemicalDispatcher : public Dispatcher
{
  public:
    Action *getHandler(string action);
};

#endif /* CHEMICALDISPATCHER_H_ */

