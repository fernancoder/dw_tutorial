#ifndef GETPOPULATIONACTION_H_
#define GETPOPULATIONACTION_H_

#include "daework-include.h"
#include "daework-kernel.h"
#include "GeosrvAction.h"

class GetPopulationAction : public GeosrvAction
{
    public:
        static  GetPopulationAction *createHandler();
        void execute();
};

#endif /* GETPOPULATIONACTION_H_ */
