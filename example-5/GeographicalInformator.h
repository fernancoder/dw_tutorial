#ifndef GESOGRAPHICALINFORMATOR_H_
#define GESOGRAPHICALINFORMATOR_H_

#include "daework-include.h"

class GeographicalInformator
{
    private:
        map<string, vector<string> > mapCountry;
        string dataFilePath;

    public:
        GeographicalInformator(string dataFilePath);
        ~GeographicalInformator();
        bool init();
        bool verifyCountry(string country);
        string getCapital(string country);
        string getArea(string country);
        string getPopulation(string country);

        void trace();

    private:
        vector<string> stringToVector(string data);
        string normalizeCountry(string country);
        int utf8CharSize (const unsigned char c);
};

#endif /* GESOGRAPHICALINFORMATOR_H_ */
