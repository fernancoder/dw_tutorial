#include "GeographicalInformator.h"


const int MAX_COUNTRY_SIZE=512;

char oneCharNorm[] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
                                          0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
                                          0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
                                          0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
                                          0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
                                          0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
                                          0x60,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
                                          0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x7B,0x7C,0x7D,0x4E,0x20};

int twoCharNorm[] = {0x41,0x41,0x41,0x41,0x41,0x41,0xC6,0xC7,0x45,0x45,0x45,0x45,0x55,0x55,0x55,0x55,
                             0xD0,0xD1,0x4F,0x4F,0x4F,0x4F,0x4F,0xD7,0xD8,0x55,0x55,0x55,0x55,0x59,0xDE,0xDF,
                             0x41,0x41,0x41,0x41,0x41,0x41,0xC6,0xC7,0x45,0x45,0x45,0x45,0x49,0x49,0x49,0x49,
                             0xD0,0xD1,0x4F,0x4F,0x4F,0x4F,0x4F,0xF7,0xD8,0x55,0x55,0x55,0x55,0x59,0xD0,0x59};

bool GeographicalInformator::verifyCountry(string country)
{
    country = normalizeCountry(country);
    return this->mapCountry.find(country) != this->mapCountry.end();
}

string GeographicalInformator::getCapital(string country)
{
    country = normalizeCountry(country);
    if ( !this->verifyCountry(country) )
	return string("");
    return this->mapCountry[country][3];
}

string GeographicalInformator::getArea(string country)
{
    country = normalizeCountry(country);
    if ( !this->verifyCountry(country) )
        return string("");
    return this->mapCountry[country][6];
}

string GeographicalInformator::getPopulation(string country)
{
    country = normalizeCountry(country);
    if ( !this->verifyCountry(country) )
        return string("");
    return this->mapCountry[country][5];
}

GeographicalInformator::GeographicalInformator(string dataFilePath)
{
    this->dataFilePath = dataFilePath;
}

GeographicalInformator::~GeographicalInformator()
{

}

bool GeographicalInformator::init()
{
    fstream dataFh;
    dataFh.open(this->dataFilePath.c_str(), std::ios_base::in);
    if ( dataFh.fail() )
        return false;

    string line;
    vector<string> vCountry;
    while ( getline(dataFh, line) )
    {
        vCountry = stringToVector(line);
        mapCountry[vCountry[0]] = vCountry;
    }
    dataFh.close();

    return true;
}

vector<string> GeographicalInformator::stringToVector(string data)
{
    vector<string> vData;
    char delim = '|';

    vData.push_back("NORMAL");

    string buf = "";
    int i = 0;
    while (i < data.length()) {
        if (data[i] != delim)
            buf += data[i];
        else if (buf.length() > 0) {
            vData.push_back(buf);
            buf = "";
        }
        i++;
    }
    if (!buf.empty())
        vData.push_back(buf);

    vData[0] = normalizeCountry(vData[2]);

    return vData;
}

int GeographicalInformator::utf8CharSize (const unsigned char c)
{
        if ((c & 0x80) == 0x00) return 1;
        if ((c & 0xE0) == 0xC0) return 2;
        if ((c & 0xF0) == 0xE0) return 3;
        return 0;
}

string GeographicalInformator::normalizeCountry(string country)
{
    unsigned char NormalizedCountry[MAX_COUNTRY_SIZE];
    unsigned char *pNormalizedCountry = NormalizedCountry;
    int curSize = 0;

    const unsigned char *pCountry = (const unsigned char *)country.c_str();
    while ( *pCountry )
    {
        switch ( utf8CharSize(*pCountry) )
        {
            case 0: //Caracter no admitido
                pCountry++;
            break;
            case 1:
                *pNormalizedCountry++ = oneCharNorm[(int)*pCountry++];
                curSize++;
            break;
            case 2:
                if ( (int)*pCountry == 0xC3 && ((int)*(pCountry+1)) >= 0x80 )
                {
                    *pNormalizedCountry++ = twoCharNorm[((int)*(pCountry+1))-0x80];
                    curSize++;
                }
                pCountry++;
                if ( *pCountry )
                    pCountry++;
            break;
            case 3:
                pCountry += 3;
            break;
        }
        if ( curSize + 5 >= MAX_COUNTRY_SIZE )
            break;
    }

    *pNormalizedCountry = '\0';
    return string((const char*)NormalizedCountry);
}

void GeographicalInformator::trace()
{
    for (map<string, vector<string> >::iterator iter = mapCountry.begin(); iter != mapCountry.end(); iter++) 
    {
        cout << iter->first << endl;
    }
}
