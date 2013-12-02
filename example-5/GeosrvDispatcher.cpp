#include "GeosrvDispatcher.h"
#include "GetCapitalAction.h"
#include "GetAreaAction.h"
#include "GetPopulationAction.h"



Action *GeosrvDispatcher::getHandler(string action)
{

        if ( action.compare("getCapital") == 0 )
                return GetCapitalAction::createHandler();

        if ( action.compare("getArea") == 0 )
                return GetAreaAction::createHandler();

        if ( action.compare("getPopulation") == 0 )
                return GetPopulationAction::createHandler();

        return defaultAction(action);

}
