#include "FormulaToText.h"
#include "ChemicalTraslator.h"
#include "daework-support.h"
#include "ChemicalTraslatorHelper.h"
#include "ChemicalTraslatorPool.h"

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

        ChemicalTraslatorHelper *chemicalTraslatorHelper = (ChemicalTraslatorHelper *)(ChemicalTraslatorPool::getInstance())->getHelper();
        int err = chemicalTraslatorHelper->getText(formula, &text);
        ChemicalTraslatorPool::getInstance()->releaseHelper((ModuleHelper *)chemicalTraslatorHelper);

        if ( err == ChemicalTraslator::TRASLATOR_NO_ERROR )
            this->processSuccess("formulaToText", text);
        else
            this->processError("formulaToText", err, ChemicalTraslator::errorMessage[err]);
    }
    this->closeConnection();
}

