#include "GetAreaAction.h"
#include "daework-support.h"
#include "GeographicalInformator.h"
#include "GeosrvThread.h"

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

    GeographicalInformator *geographicalInformator = ((GeosrvThread *)(this->getThread()))->getGeographicalInformator();

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

    this->closeConnection();
}

