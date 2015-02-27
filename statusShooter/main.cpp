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
	ramData.getData('M');
	swapData.getData('M');
	temperatureData.getTemperatureData('M');
	processorData.ReadCpuData('M');
	std::cout << processorData.GetCpuFreqString() << std::endl;
	std::cout << swapData.GetmData() << std::endl;
	std::cout << ramData.getRamDataCapacity() << std::endl;
	std::cout << temperatureData.GetmStringTemp() << std::endl;
	while(true)
	{
		shooter.addToSql(processorData.GetCpuFreqString(), ramData.getRamDataCapacity(), temperatureData.GetmStringTemp(),swapData.GetmData());
	}
	return status;
}