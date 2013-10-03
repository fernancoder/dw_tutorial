#include "FormulaToText.h"
#include "ChemicalTraslator.h"
#include "daework-support.h"

FormulaToText *FormulaToText::createHandler()
{
    return new FormulaToText();
}

void FormulaToText::execute()
{
    string formula = this->getRequestParam("formula");
    if ( formula.empty() )
    {
      this->sendError(2001, "El parámetro formula no viene informado en la petición");
      string logMsg = "info.action=#formulaToText#;info.error.id=#2001#;info.error.message=#El parámetro formula no viene informado en la petición#";
      LogManager::getInstance()->write(logMsg, LOG_INFO);
      this->closeConnection();
      return;
    }
    string text;

    ChemicalTraslator *chemicalTraslator = new ChemicalTraslator();

    string logMsg = "info.action=#formulaToText#;info.request.formula=#";
    logMsg.append(formula);
    logMsg.append("#");
    LogManager::getInstance()->write(logMsg, LOG_INFO);

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
    {
        this->sendError(err, ChemicalTraslator::errorMessage[err]);
        logMsg = "info.action=#formulaToText#;info.error.id=#";
        logMsg.append(Util::intToString(err));
        logMsg.append("#;info.error.message=#");
        logMsg.append(ChemicalTraslator::errorMessage[err]);
        logMsg.append("#");
        LogManager::getInstance()->write(logMsg, LOG_INFO);
    }

    this->closeConnection();
}

