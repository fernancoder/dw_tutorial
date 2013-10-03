#ifndef CHEMICALTRASLATOR_H_
#define CHEMICALTRASLATOR_H_

#include "daework-include.h"

class ChemicalTraslator
{
  public:
    int getText(string formula, string *text);
    int getFormula(string text, string *formula);
  
  public:
    static const string errorMessage[];

    static const int TRASLATOR_NO_ERROR;
};

#endif /* CHEMICALTRASLATOR_H_ */
