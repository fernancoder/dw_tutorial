#ifndef GESOSRVDISPATCHER_H_
#define GESOSRVDISPATCHER_H_

#include "daework-kernel.h"


class GesosrvDispatcher : public Dispatcher
{
        public:
                Action *getHandler(string action);

};

#endif /* GESOSRVDISPATCHER_H_ */
