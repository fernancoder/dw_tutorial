#include <getopt.h>

#include "daework-kernel.h"
#include "daework-support.h"
#include "GeosrvServer.h"


const char* config_filename = NULL;
const char* data_filename = NULL;
int asDaemon = 0;

void use(const char *progName)
{
        cout << endl;
        cout << "Usage: " << progName << " [-h] | [-D] [-c filename] [-d datafile]" << endl;
        cout << "\t -h --help :                   Display this usage information" << endl;
        cout << "\t -D --daemon :                 Run as a daemon" << endl;
        cout << "\t -c --configuration filename : Configuration file (default: test.ini)" << endl;
        cout << "\t -d --datafile               : Geografical information text file (default: geosrv.inf)" << endl << endl;
        exit(0);
}

void verifyParams (int argc, char **argv)
{
        const char* const short_options = "hDcd:";

        const struct option long_options[] = {
            { "help", 0, NULL, 'h' },
            { "daemon", 0, NULL, 'D' },
            { "configuration", 1, NULL, 'c' },
            { "datafile", 1, NULL, 'd' },
            { NULL, 0, NULL, 0 }
        };

        const char* program_name = "geosrv";
        int next_option;

        do {
            next_option = getopt_long (argc, argv, short_options,long_options, NULL);
            switch (next_option)
            {
                case 'h':
                case '?':
                use(program_name);
            break;
                case 'c':
                    config_filename = optarg;
                break;
                case 'D':
                        asDaemon = 1;
                break;
                case 'd':
                        data_filename = optarg;
                break;
                case -1:
                break;
                default:
                        use(program_name);
                break;
            }
        }
        while (next_option != -1);
}

int main (int argc, char **argv)
{
    verifyParams(argc, argv);

    char cfgFilePath[512];
    if ( config_filename == NULL )
        strcpy(cfgFilePath, "./geosrv.ini");
    else
        strcpy(cfgFilePath, config_filename);


    char *appEnv = getenv("APPLICATION_ENV");
    if ( appEnv == NULL )
        appEnv = "des";    

    char dataFilePath[512];
    if ( data_filename == NULL )
        strcpy(dataFilePath, "./geosrv.inf");
    else
        strcpy(dataFilePath, data_filename);
   
    GeosrvServer *server = new GeosrvServer(cfgFilePath, appEnv, "main");
    CmdLineParamManager::getInstance()->setCmdLineParam("data_filename",dataFilePath);
    Daemonizer::daemonize(server,asDaemon==1);

    return 0;
}
