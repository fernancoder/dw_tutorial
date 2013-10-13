#include "daework-support.h"

class ChemicalTraslatorPool : public ModulePool
{
  private:
    static bool instanceFlag;
    static ChemicalTraslatorPool * chemicalTraslatorPool;

  public:
    static ChemicalTraslatorPool* getInstance();

    ModuleHelper *newHelper();
};

