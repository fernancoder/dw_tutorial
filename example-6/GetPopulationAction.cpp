#include "GetPopulationAction.h"
#include "daework-support.h"
#include "GeographicalInformator.h"
#include "GeographicalInformatorHelper.h"
#include "GeographicalInformatorPool.h"
#include "GeosrvServer.h"

GetPopulationAction *GetPopulationAction::createHandler()
{
    return new GetPopulationAction();
}

void GetPopulationAction::execute()
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
        string response = "\"population\" : \"";
        response.append(geographicalInformator->getPopulation(country));
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

