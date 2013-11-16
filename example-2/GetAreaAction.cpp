#include "GetAreaAction.h"
#include "daework-support.h"
#include "GeographicalInformator.h"

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

    GeographicalInformator *geographicalInformator = new GeographicalInformator();
    string country = this->getRequestParam("country");
    if ( geographicalInformator->verifyCountry(country) )
    {
        string response = "\"area\" : \"";
        response.append(geographicalInformator->getArea(country));
        response.append(" Km2\"");
        this->processSuccess(response);
    }
    else
    {
        this->processError(1001,"Country doesn't exsit");
    }
    delete geographicalInformator;

    this->closeConnection();
}

