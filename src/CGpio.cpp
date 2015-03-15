#include "../include/CGPio.h"
#include <iostream>
CGPio::CGPio(short int pin)
{
	this->mPin = pin;
}
void CGPio::setState(bool newState) ///needs to be either high or low
{
	
	bcm2835_gpio_write(this->mPin, newState);
	//std::cout << "setting pin " << this->mPin << " state to " << newState << std::endl;
	this->mPinState = newState;
}
void CGPio::setDirection(int direction)
{
	bcm2835_gpio_fsel(this->mPin, direction);
	//std::cout << "setting pin " << this->mPin << " direction to " << direction << std::endl;
	this->mGpioDirection = direction;
}

CGPio::~CGPio()
{

}