/*
TODO: read data about CPU, SWAP, RAM, TEMP and insert to SQL.
Read config from file (standard path)
*/
#include "CCpu.h"
#include "CRam.h"
#include "CSwap.h"
#include "CTemperature.h"
#include <glog/logging.h>
#include "CStatusShooter.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    google::InitGoogleLogging(argv[0]);
    google::InstallFailureSignalHandler();
    pid_t pid = 0, sid = 0;
    CCpu processorData;
    CRam ramData;
    CSwap swapData;
    CTemperature temperatureData;
    CStatusShooter shooter;
    int status = 0;
    pid = fork();
    if(pid < 0)
    {
        std::cout << "Cannot fork off" << std::endl;
        LOG(FATAL) << "Cannot fork off";
        exit(-1);
    }
    if(pid > 0)
    {
        LOG(INFO) << "forked succesfully";
        std::cout << "forked succesfully" << std::endl;
        exit(0);
    }
    umask(0);
    sid = setsid();

    if(sid < 0)
    {
        std::cout << "cannot set session ID" << std::endl;
        LOG(FATAL) << "Cannot set sid, exiting";
        exit(-1);
    }
    if((chdir("/")) < 0)
    {
        std::cout << "Cannot change directory" << std::endl;
        LOG(FATAL) << "Cannot change diretctory to /";
        exit(-1);
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
	while(true)
	{  
		ramData.getData('N');
		swapData.getData('N');
		temperatureData.getTemperatureData('N');
		processorData.ReadCpuData('N');
        shooter.addToSql(processorData.GetCpuFreqString(), ramData.getRamDataCapacity(), temperatureData.GetmStringTemp(),swapData.GetmData());
		usleep(1000000);
	}
	return status;
}
