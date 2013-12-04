#include "GetCapitalAction.h"
#include "daework-support.h"
#include "GeographicalInformator.h"
#include "GeosrvThread.h"

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

    GeographicalInformator *geographicalInformator = ((GeosrvThread *)(this->getThread()))->getGeographicalInformator();        
    
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

    this->closeConnection();
}

