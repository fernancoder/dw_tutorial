#include "ChemicalTraslator.h"

const string ChemicalTraslator::errorMessage[] = {
  string(""), 
  string("Bad formula format") 
};
const int ChemicalTraslator::TRASLATOR_NO_ERROR = 0;


int ChemicalTraslator::getText(string formula, string *text)
{
  return 1;
}

int ChemicalTraslator::getFormula(string text, string *formula)
{
  return 1;
}

