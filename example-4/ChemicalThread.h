#ifndef CHEMICALTHREAD_H_
#define CHEMICALTHREAD_H_

#include "daework-kernel.h"
#include "ChemicalTraslator.h"

class ChemicalThread : public Thread
{
  public:
    void init();

    ~ChemicalThread();

    int getChemicalTraslatorText(string formula, string *text);
    int getChemicalTraslatorFormula(string text, string *formula);

  private:
    ChemicalTraslator *chemicalTraslator;
};

#endif /* CHEMICALTHREAD_H_ */

