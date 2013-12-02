#ifndef GETAREAACTION_H_
#define GETAREAACTION_H_

#include "daework-include.h"
#include "daework-kernel.h"
#include "GeosrvAction.h"

class GetAreaAction : public GeosrvAction
{
    public:
        static  GetAreaAction *createHandler();
        void execute();
};

#endif /* GETAREAACTION_H_ */
