#include "ChemicalAction.h"


bool ChemicalAction::verifyParam(string actionName, string param, int errorId, string errorMsg)
{
    if ( !param.empty() )
        return true;

    this->sendError(errorId, errorMsg);
    string logMsg = "info.action=#";
    logMsg.append(actionName);
    logMsg.append("#;info.error.id=#");
    logMsg.append(Util::intToString(errorId));
    logMsg.append("#;info.error.message=#");
    logMsg.append(errorMsg);
    logMsg.append("#");
    LogManager::getInstance()->write(logMsg, LOG_INFO);

    return false;
}

void ChemicalAction::logAction(string actionName, string param)
{
    string logMsg = "info.action=#";
    logMsg.append(actionName);
    logMsg.append("#;info.request.");
    if ( actionName.compare("formulaToText") == 0 )
       logMsg.append("formula");
    else
       logMsg.append("text");
    logMsg.append("=#");
    logMsg.append(param);
    logMsg.append("#");
    LogManager::getInstance()->write(logMsg, LOG_INFO);
}

void ChemicalAction::processSuccess(string actionName, string result)
{
    string response;
    if ( actionName.compare("formulaToText") == 0 )   
        string response = "\"text\" : \"";
    else
        string response = "\"formula\" : \"";
    response.append(result);
    response.append("\"");

    this->sendSuccess(response);
}

void ChemicalAction::processError(string actionName, int errorId, string errorMsg)
{
    this->sendError(errorId, errorMsg);
    string logMsg = "info.action=#";
    logMsg.append(actionName);
    logMsg.append("#;info.error.id=#");
    logMsg.append(Util::intToString(errorId));
    logMsg.append("#;info.error.message=#");
    logMsg.append(errorMsg);
    logMsg.append("#");
    LogManager::getInstance()->write(logMsg, LOG_INFO);
}

