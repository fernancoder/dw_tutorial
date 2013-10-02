#include "FormulaToText.h"
#include "ChemicalTraslator.h"

FormulaToText *FormulaToText::createHandler()
{
    return new FormulaToText();
}

void FormulaToText::execute()
{
    ChemicalTraslator *chemicalTraslator = new ChemicalTraslator();

    string formula = this->getRequestParam("formula");
    string text;

    int err = chemicalTraslator->getText(formula,&text);

    delete chemicalTraslator;

    if ( err == ChemicalTraslator::TRASLATOR_NO_ERROR )
    {
        string response = "\"text\" : \"";
        response.append(text);
        response.append("\"");

        this->sendSuccess(response);
    }
    else
        this->sendError(err, ChemicalTraslator::errorMessage[err]);

    this->closeConnection();
}

