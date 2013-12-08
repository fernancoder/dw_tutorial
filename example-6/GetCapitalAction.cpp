#include "GetCapitalAction.h"
#include "daework-support.h"
#include "GeographicalInformator.h"
#include "GeographicalInformatorHelper.h"
#include "GeographicalInformatorPool.h"
#include "GeosrvServer.h"

GetCapitalAction *GetCapitalAction::createHandler()
{
    return new GetCapitalAction();
}

void GetCapitalAction::execute()
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
        string response = "\"capital\" : \"";
        response.append(geographicalInformator->getCapital(country));
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

