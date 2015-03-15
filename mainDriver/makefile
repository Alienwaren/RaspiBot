CXX=g++
INC=../include
SRC=../src
all: gpio network
	$(CXX) gpio.o network.o main.cpp -I$(INC) -o main.o -lbcm2835  -lsfml-network -Ofast -Wall
gpio:
	$(CXX) -c $(SRC)/CGpio.cpp -o gpio.o -lbcm2835 -Ofast -Wall 
network:
	$(CXX) -c $(SRC)/CUdpReceiver.cpp -o network.o -lsfml-network -Ofast -Wall