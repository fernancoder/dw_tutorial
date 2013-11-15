#ifndef GEOSRVDISPATCHER_H_
#define GEOSRVDISPATCHER_H_

#include "daework-kernel.h"


class GeosrvDispatcher : public Dispatcher
{
        public:
                Action *getHandler(string action);

};

#endif /* GEOSRVDISPATCHER_H_ */
