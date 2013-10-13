#include "daework-support.h"
#include "ChemicalTraslatorHelper.h"
#include "ChemicalTraslatorPool.h"

bool ChemicalTraslatorPool::instanceFlag=0;
ChemicalTraslatorPool *ChemicalTraslatorPool::chemicalTraslatorPool=0;

ChemicalTraslatorPool *ChemicalTraslatorPool::getInstance()
{
    if(!instanceFlag)
    {
    	chemicalTraslatorPool = new ChemicalTraslatorPool();
    	instanceFlag = true;
    	return chemicalTraslatorPool;
    }
    else
    {
    	return chemicalTraslatorPool;
    }
}

ModuleHelper *ChemicalTraslatorPool::newHelper()
{
    return (ModuleHelper *)(new ChemicalTraslatorHelper());
}

