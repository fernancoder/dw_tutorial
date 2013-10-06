#ifndef CHEMICALACTION_H_
#define CHEMICALACTION_H_

#include "daework-include.h"
#include "daework-kernel.h"
#include "daework-support.h"

class ChemicalAction : public Action
{
  public:
    bool verifyParam(string actionName, string param, int errorId, string errorMsg);
    void logAction(string actionName, string param);
    void processSuccess(string actionName, string result);
    void processError(string actionName, int errorId, string errorMsg);
};

#endif /* CHEMICLACTIONN_H_ */
