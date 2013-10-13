#include "TextToFormula.h"
#include "ChemicalTraslator.h"
#include "daework-support.h"
#include "ChemicalTraslatorHelper.h"
#include "ChemicalTraslatorPool.h"

TextToFormula *TextToFormula::createHandler()
{
    return new TextToFormula();
}

void TextToFormula::execute()
{
    string formula;
    string text = this->getRequestParam("text");
    if ( this->verifyParam("textToormula", text, 2002, "El parámetro text no viene informado en la petición") )
    {
        this->logAction("textToFormula",text);

        ChemicalTraslatorHelper *chemicalTraslatorHelper = (ChemicalTraslatorHelper *)(ChemicalTraslatorPool::getInstance())->getHelper();
        int err = chemicalTraslatorHelper->getFormula(text, &formula);
        ChemicalTraslatorPool::getInstance()->releaseHelper((ModuleHelper *)chemicalTraslatorHelper);

        if ( err == ChemicalTraslator::TRASLATOR_NO_ERROR )
            this->processSuccess("textToFormula", text);
        else
            this->processError("textToFormula", err, ChemicalTraslator::errorMessage[err]);
    }
    this->closeConnection();
}

