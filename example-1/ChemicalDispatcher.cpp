#include "ChemicalDispatcher.h"
#include "TextToFormula.h"
#include "FormulaToText.h"

Action *ChemicalDispatcher::getHandler(string action)
{
  if ( action.compare("textToFormula") == 0 )
    return TextToFormula::createHandler();
  if ( action.compare("formulaToText") == 0 )
    return FormulaToText::createHandler();

  return defaultAction(action);
}

