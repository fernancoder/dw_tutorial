#include "GetCapitalAction.h"
#include "daework-support.h"

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


    //Change this and put your stuff here
    string response = "\"stuff\" : \"OK\"";
    this->sendSuccess(response);
    //end

    this->closeConnection();
}

