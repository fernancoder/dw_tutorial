#ifndef GEOSRVACTION_H_
#define GEOSRVACTION_H_

#include "daework-include.h"
#include "daework-kernel.h"
#include "daework-support.h"

class GeosrvAction : public Action
{
  public:
    bool verifyParam(string param, int errorId, string errorMsg);
    void logAction();
    void processSuccess(string result);
    void processError(int errorId, string errorMsg);
};

#endif /* GEOSRVACTION_H_ */
