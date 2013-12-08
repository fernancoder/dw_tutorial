#include "GetAreaAction.h"
#include "daework-support.h"
#include "GeographicalInformator.h"
#include "GeographicalInformatorHelper.h"
#include "GeographicalInformatorPool.h"
#include "GeosrvServer.h"

GetAreaAction *GetAreaAction::createHandler()
{
    return new GetAreaAction();
}

void GetAreaAction::execute()
{
    if ( !verifyParam(this->getRequestParam("country"),1000,"Parameter country is mandatory") )
    {
        this->closeConnection();
        return;
    }

    GeographicalInformatorHelper *geographicalInformator = (GeographicalInformatorHelper *)(GeographicalInformatorPool::getInstance())->getHelper();

    string country = this->getRequestParam("country");
    if ( geographicalInformator->verifyCountry(country) )
    {
        string response = "\"area\" : \"";
        response.append(geographicalInformator->getArea(country));
        response.append("\"");
        this->processSuccess(response);
    }
    else
    {
        this->processError(1001,"Country doesn't exsit");
    }

    GeographicalInformatorPool::getInstance()->releaseHelper((ModuleHelper *)geographicalInformator);

    this->closeConnection();
}

