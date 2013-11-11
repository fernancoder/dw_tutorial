#ifndef GETPOPULATIONACTION_H_
#define GETPOPULATIONACTION_H_

#include "daework-include.h"
#include "daework-kernel.h"
#include "GesosrvAction.h"

class GetPopulationAction : public GesosrvAction
{
    public:
        static  GetPopulationAction *createHandler();
        void execute();
};

#endif /* GETPOPULATIONACTION_H_ */
