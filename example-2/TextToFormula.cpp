#include "TextToFormula.h"
#include "ChemicalTraslator.h"
#include "daework-support.h"

TextToFormula *TextToFormula::createHandler()
{
    return new TextToFormula();
}

void TextToFormula::execute()
{
    string text = this->getRequestParam("text");
    if ( text.empty() )
    {
      this->sendError(2002, "El parámetro text no viene informado en la petición");
      string logMsg = "info.action=#textToFormula#;info.error.id=#2002#;info.error.message=#El parámetro text no viene informado en la petición#";
      LogManager::getInstance()->write(logMsg, LOG_INFO);
      this->closeConnection();
      return;
    }
    string formula;

    ChemicalTraslator *chemicalTraslator = new ChemicalTraslator();

    string logMsg = "info.action=#textToFormula#;info.request.text=#";
    logMsg.append(text);
    logMsg.append("#");
    LogManager::getInstance()->write(logMsg, LOG_INFO);

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
    {
        this->sendError(err, ChemicalTraslator::errorMessage[err]);
        logMsg = "info.action=#textToFormula#;info.error.id=#";
        logMsg.append(Util::intToString(err));
        logMsg.append("#;info.error.message=#");
        logMsg.append(ChemicalTraslator::errorMessage[err]);
        logMsg.append("#");
        LogManager::getInstance()->write(logMsg, LOG_INFO);
    }

    this->closeConnection();
}

