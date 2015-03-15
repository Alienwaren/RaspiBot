#include "CGPio.h"
#include "CUdpReceiver.h"
#include <string>
int main(int argc, char const *argv[])
{
	if (!bcm2835_init())
		return 1;
	CUdpReceiver recv(1234);
	CGPio fiveVoltDriverPin(RPI_GPIO_P1_12); //create pin object
	CGPio steeringPinLeft(RPI_GPIO_P1_26);
	CGPio steeringPinRight(RPI_GPIO_P1_24);
	CGPio onwardsPin(RPI_GPIO_P1_22);
	CGPio backwardsPin(RPI_GPIO_P1_18);
	CGPio en1(RPI_GPIO_P1_23);
	CGPio en2(RPI_GPIO_P1_21);
	fiveVoltDriverPin.setDirection(CGPio::OUTPUT);
	fiveVoltDriverPin.setState(HIGH);
	std::string command = "";
	while(true)
	{
		command = recv.getMessage();
		if(command.find("throttle") != std::string::npos)
		{
			std::cout << "onwards" << std::endl;
		}
	}
}
