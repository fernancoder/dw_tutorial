#include "GesosrvAction.h"


bool GesosrvAction::verifyParam(string param, int errorId, string errorMsg)
{
    if ( !param.empty() )
        return true;

    processError(errorId, errorMsg);
    return false;
}

void GesosrvAction::logAction()
{
    string logMsg = this->getLogParams();
    LogManager::getInstance()->write(logMsg, LOG_INFO);
}

void GesosrvAction::processSuccess(string result)
{
    this->logAction();
    this->sendSuccess(result);
}

void GesosrvAction::processError(int errorId, string errorMsg)
{
    this->sendError(errorId, errorMsg);
    string logMsg = this->getLogParams();
    logMsg.append(";info.error.id=#");
    logMsg.append(Util::intToString(errorId));
    logMsg.append("#;info.error.message=#");
    logMsg.append(errorMsg);
    logMsg.append("#");
    LogManager::getInstance()->write(logMsg, LOG_INFO);
}

