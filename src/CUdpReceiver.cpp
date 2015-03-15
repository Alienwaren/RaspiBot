#include "../include/CUdpReceiver.h"

CUdpReceiver::CUdpReceiver(int port)
	: maxMessageSize(10) //to be read from config
{
	if(this->receiver.bind(port) != sf::Socket::Done)
	{
		std::cout << "cannot bind to this port: " << port << std::endl;
	}
	receiver.setBlocking(true);
}
std::string CUdpReceiver::getMessage()
{
	char data[maxMessageSize];
	sf::IpAddress sender;
	unsigned short port; 
	std::size_t received;
	if(receiver.receive(data, maxMessageSize, received, sender, port) != sf::Socket::Done)
	{
		
		return "no data";

	}else
	{
		std::string dataAsString(data);
		return dataAsString;
	}
}
CUdpReceiver::~CUdpReceiver()
{

}