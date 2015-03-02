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

pid_t pid, sid;
void forkOff()
{
	pid = fork();
	if(pid < 0)
	{
		exit(-1);
	}
	if(pid > 0)
	{
		exit(0);
	}
	umask(0);
	sid = setsid();
	// google::InitGoogleLogging(argv[0]);
	if(sid < 0)
	{
		// LOG(ERROR) << "Cannot set sid, exiting";
		exit(-1);
	}
	if((chdir("/")) < 0)
	{
		// LOG(ERROR) << "Cannot change diretctory to /";
		exit(-1);
	}
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
        
}
int main(int argc, char const *argv[])
{
	forkOff();
	CCpu processorData;
	CRam ramData;
	CSwap swapData;
	CTemperature temperatureData;
	CStatusShooter shooter;
	int status = 0;
	while(true)
	{
		shooter.addToSql(processorData.GetCpuFreqString(), ramData.getRamDataCapacity(), temperatureData.GetmStringTemp(),swapData.GetmData());
		ramData.getData('N');
		swapData.getData('N');
		temperatureData.getTemperatureData('N');
		processorData.ReadCpuData('N');
		LOG(INFO) << "Addiding data to SQL";
		usleep(1000000);
	}
	return status;
}
