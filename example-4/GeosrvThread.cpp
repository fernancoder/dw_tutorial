#include "GeosrvThread.h"

void GeosrvThread::init()
{
    this->geographicalInformator = new GeographicalInformator(CmdLineParamManager::getInstance()->getCmdLineParam("data_filename"));
    this->geographicalInformator->init();
}
