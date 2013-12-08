#include "daework-support.h"
#include "GeographicalInformatorHelper.h"
#include "GeographicalInformatorPool.h"

bool GeographicalInformatorPool::instanceFlag=0;
GeographicalInformatorPool *GeographicalInformatorPool::geographicalInformatorPool=0;

GeographicalInformatorPool *GeographicalInformatorPool::getInstance()
{
    if(!instanceFlag)
    {
        geographicalInformatorPool = new GeographicalInformatorPool();
        instanceFlag = true;
        return geographicalInformatorPool;
    }
    else
    {
        return geographicalInformatorPool;
    }
}

ModuleHelper *GeographicalInformatorPool::newHelper()
{
    return (ModuleHelper *)(new GeographicalInformatorHelper());
}

