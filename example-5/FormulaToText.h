#ifndef FORMULATOTEXT_H_
#define FORMULATOTEXT_H_

#include "daework-include.h"
#include "daework-kernel.h"
#include "ChemicalAction.h"

class FormulaToText : public ChemicalAction
{
    public:
        static  FormulaToText *createHandler();
        void execute();
};

#endif /* FORMULATOTEXT_H_ */
