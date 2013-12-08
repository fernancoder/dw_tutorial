#include "daework-support.h"

class GeographicalInformatorPool : public ModulePool
{
  private:
    static bool instanceFlag;
    static GeographicalInformatorPool * geographicalInformatorPool;

  public:
    static GeographicalInformatorPool* getInstance();

    ModuleHelper *newHelper();
};

