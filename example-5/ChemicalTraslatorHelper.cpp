#include "daework-support.h"
#include "ChemicalTraslatorHelper.h"

ChemicalTraslatorHelper::ChemicalTraslatorHelper()
{
    this->chemicalTraslator = new ChemicalTraslator();
}

ChemicalTraslatorHelper::~ChemicalTraslatorHelper()
{
    delete this->chemicalTraslator;
}

int ChemicalTraslatorHelper::getText(string formula, string *text)
{
    return this->chemicalTraslator->getText(formula, text);
}

int ChemicalTraslatorHelper::getFormula(string text, string *formula)
{
    return this->chemicalTraslator->getFormula(text, formula);
}

