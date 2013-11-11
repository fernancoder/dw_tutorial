#include "GesosrvDispatcher.h"
#include "GetCapitalAction.h"
#include "GetAreaAction.h"
#include "GetPopulationAction.h"



Action *GesosrvDispatcher::getHandler(string action)
{

        //Esto será una tabla o una clase o similar

        if ( action.compare("getCapital") == 0 )
                return GetCapitalAction::createHandler();

        if ( action.compare("getArea") == 0 )
                return GetAreaAction::createHandler();

        if ( action.compare("getPopulation") == 0 )
                return GetPopulationAction::createHandler();

        return defaultAction(action);

}
