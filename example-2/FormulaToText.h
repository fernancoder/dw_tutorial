#ifndef FORMULATOTEXT_H_
#define FORMULATOTEXT_H_

#include "daework-include.h"
#include "daework-kernel.h"

class FormulaToText : public Action
{
    public:
        static  FormulaToText *createHandler();
        void execute();
};

#endif /* FORMULATOTEXT_H_ */
