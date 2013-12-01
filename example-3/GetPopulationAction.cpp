#include "GetPopulationAction.h"
#include "daework-support.h"
#include "GeographicalInformator.h"

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

    GeographicalInformator *geographicalInformator = new GeographicalInformator(getCmdLineParam("data_filename"));
    if ( !geographicalInformator->init() )
    {
        this->processError(1002,"Geographical data file doesn't exsit");
    }
    else
    {
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
    }
    delete geographicalInformator;

    this->closeConnection();
}

