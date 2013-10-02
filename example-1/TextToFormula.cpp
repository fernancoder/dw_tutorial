#include "TextToFormula.h"
#include "ChemicalTraslator.h"

TextToFormula *TextToFormula::createHandler()
{
    return new TextToFormula();
}

void TextToFormula::execute()
{
    ChemicalTraslator *chemicalTraslator = new ChemicalTraslator();

    string text = this->getRequestParam("text");
    string formula;

    int err = chemicalTraslator->getFormula(text, &formula);

    delete chemicalTraslator;

    if ( err == ChemicalTraslator::TRASLATOR_NO_ERROR )
    {
        string response = "\"formula\" : \"";
        response.append(formula);
        response.append("\"");

        this->sendSuccess(response);
    }
    else
        this->sendError(err, ChemicalTraslator::errorMessage[err]);

    this->closeConnection();
}

