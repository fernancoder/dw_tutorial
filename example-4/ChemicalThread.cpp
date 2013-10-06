#include "ChemicalThread.h"

void ChemicalThread::init()
{
  this->chemicalTraslator = new ChemicalTraslator();
}

ChemicalThread::~ChemicalThread()
{
   delete this->chemicalTraslator;
}

int ChemicalThread::getChemicalTraslatorText(string formula, string *text)
{
  return this->chemicalTraslator->getText(formula, text);
}

int ChemicalThread::getChemicalTraslatorFormula(string text, string *formula)
{
  return this->chemicalTraslator->getFormula(text, formula);
}

