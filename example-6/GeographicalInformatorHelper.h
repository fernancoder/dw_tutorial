#include "GeographicalInformator.h"

class GeographicalInformatorHelper : public ModuleHelper
{
  public:
    GeographicalInformatorHelper();
    ~GeographicalInformatorHelper();

    bool verifyCountry(string country);
    string getCapital(string country);
    string getArea(string country);
    string getPopulation(string country);

  private:
    GeographicalInformator *geographicalInformator;
};

