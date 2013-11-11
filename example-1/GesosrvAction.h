#ifndef GESOSRVACTION_H_
#define GESOSRVACTION_H_

#include "daework-include.h"
#include "daework-kernel.h"
#include "daework-support.h"

class GesosrvAction : public Action
{
  public:
    bool verifyParam(string param, int errorId, string errorMsg);
    void logAction();
    void processSuccess(string result);
    void processError(int errorId, string errorMsg);
};

#endif /* GESOSRVACTION_H_ */
