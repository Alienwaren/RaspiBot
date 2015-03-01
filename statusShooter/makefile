CXX=g++
SRC=../src
INCL=../include
all: cpu ram temperature swap statusshooter
	$(CXX) main.cpp cpu.o ram.o temperature.o swap.o statusshooter.o -o main.o -I$(INCL) -Ofast -Wall -lyaml-cpp -lglog -lpqxx -lpq
cpu:
	$(CXX) -c $(SRC)/CCpu.cpp -o cpu.o -Ofast -Wall 
ram:
	$(CXX) -c $(SRC)/CRam.cpp -o ram.o -Ofast -Wall 
temperature:
	$(CXX) -c $(SRC)/CTemperature.cpp -o temperature.o -Ofast -Wall
swap:
	$(CXX) -c $(SRC)/CSwap.cpp -o swap.o -Ofast -Wall  
statusshooter:
	$(CXX) -c CStatusShooter.cpp -o statusshooter.o -Ofast -Wall  
