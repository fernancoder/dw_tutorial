#ifndef GETAREAACTION_H_
#define GETAREAACTION_H_

#include "daework-include.h"
#include "daework-kernel.h"
#include "GesosrvAction.h"

class GetAreaAction : public GesosrvAction
{
    public:
        static  GetAreaAction *createHandler();
        void execute();
};

#endif /* GETAREAACTION_H_ */
