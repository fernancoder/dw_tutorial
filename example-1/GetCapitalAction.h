#ifndef GETCAPITALACTION_H_
#define GETCAPITALACTION_H_

#include "daework-include.h"
#include "daework-kernel.h"
#include "GesosrvAction.h"

class GetCapitalAction : public GesosrvAction
{
    public:
        static  GetCapitalAction *createHandler();
        void execute();
};

#endif /* GETCAPITALACTION_H_ */
