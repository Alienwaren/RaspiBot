#ifndef CGPio_H
#define CGPio_H
#include <bcm2835.h>
#include <iostream>
class CGPio
{
public:
	CGPio(short int pin);
	void setPinLocal(short int newLocation) { this->mPin = newLocation; }
	short int getPinLocal() { return this->mPin; }
	void setState(bool newState);
	bool getState() { return this->mPinState; }
	void setDirection(int direction);
	void setStateWithTimeout(bool newState, unsigned long timeout);
	static const int OUTPUT = BCM2835_GPIO_FSEL_OUTP;
	static const int INPUT = BCM2835_GPIO_FSEL_INPT;
	static void wait(int delay) { bcm2835_delay(delay); }
	~CGPio();
private:
	short int mPin;
	bool mPinState;
	short int mGpioDirection;
	/* data */
};
#endif