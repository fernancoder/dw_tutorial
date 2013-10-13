#include "ChemicalTraslator.h"

class ChemicalTraslatorHelper : public ModuleHelper
{
  public:
    ChemicalTraslatorHelper();
    ~ChemicalTraslatorHelper();

    int getText(string formula, string *text);
    int getFormula(string text, string *formula);

  private:
    ChemicalTraslator *chemicalTraslator;
};
