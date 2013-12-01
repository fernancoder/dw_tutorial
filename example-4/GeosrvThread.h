#ifndef GEOSRVTHREAD_H_
#define GEOSRVTHREAD_H_

#include "daework-kernel.h"
#include "GeographicalInformator.h"

class GeosrvThread : public Thread
{
    private:
        GeographicalInformator *geographicalInformator;

    public:
        void init();
        GeographicalInformator *getGeographicalInformator(){return geographicalInformator;};

};

#endif /* GEOSRVTHREAD_H_ */
