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
int main(int argc, char const *argv[])
{
	google::InitGoogleLogging(argv[0]);
	CCpu processorData;
	CRam ramData;
	CSwap swapData;
	CTemperature temperatureData;
	CStatusShooter shooter;
	int status = 0;
	ramData.getData('N');
	swapData.getData('N');
	temperatureData.getTemperatureData('N');
	processorData.ReadCpuData('N');
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