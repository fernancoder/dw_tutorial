#ifndef TEXTTOFORMULA_H_
#define TEXTTOFORMULA_H_

#include "daework-include.h"
#include "daework-kernel.h"
#include "ChemicalAction.h"

class TextToFormula : public ChemicalAction
{
    public:
        static  TextToFormula *createHandler();
        void execute();
};

#endif /* TEXTTOFORMULA_H_ */

