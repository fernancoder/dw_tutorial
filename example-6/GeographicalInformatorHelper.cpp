#include "daework-support.h"
#include "GeographicalInformatorHelper.h"

GeographicalInformatorHelper::GeographicalInformatorHelper()
{
    this->geographicalInformator = new GeographicalInformator(CmdLineParamManager::getInstance()->getCmdLineParam("data_filename"));
    this->geographicalInformator->init();
}

GeographicalInformatorHelper::~GeographicalInformatorHelper()
{
    delete this->geographicalInformator;
}

bool GeographicalInformatorHelper::verifyCountry(string country)
{
    return this->geographicalInformator->verifyCountry(country);
}

string GeographicalInformatorHelper::getCapital(string country)
{
    return this->geographicalInformator->getCapital(country);
}

string GeographicalInformatorHelper::getArea(string country)
{
    return this->geographicalInformator->getArea(country);
}

string GeographicalInformatorHelper::getPopulation(string country)
{
    return this->geographicalInformator->getPopulation(country);
}

