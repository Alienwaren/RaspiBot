#ifndef CUdpReceiver_H
#define CUdpReceiver_H 
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
class CUdpReceiver
{
public:
	CUdpReceiver(int port);
	~CUdpReceiver();
	std::string getMessage();
private:
	sf::UdpSocket receiver;
	const int maxMessageSize;
};
#endif