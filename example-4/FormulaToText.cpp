#include "FormulaToText.h"
#include "ChemicalTraslator.h"
#include "daework-support.h"
#include "ChemicalThread.h"

FormulaToText *FormulaToText::createHandler()
{
    return new FormulaToText();
}

void FormulaToText::execute()
{
    string text;
    string formula = this->getRequestParam("formula");
    if ( this->verifyParam("formulaToText", formula, 2001, "El parámetro formula no viene informado en la petición") )
    {    
        this->logAction("formulaToText",formula);

        int err = ((ChemicalThread *)this->getThread())->getChemicalTraslatorText(formula,&text);

        if ( err == ChemicalTraslator::TRASLATOR_NO_ERROR )
            this->processSuccess("formulaToText", text);
        else
            this->processError("formulaToText", err, ChemicalTraslator::errorMessage[err]);
    }
    this->closeConnection();
}

