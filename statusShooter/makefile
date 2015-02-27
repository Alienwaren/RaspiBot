$(CXX)=g++
all: cpu ram temperature swap statusshooter
	$(CXX) main.cpp cpu.o ram.o temperature.o swap.o statusshooter.o -o main.o -Ofast -Wall -lyaml-cpp -lglog
cpu:
	$(CXX) -c CCpu.cpp -o cpu.o -Ofast -Wall 
ram:
	$(CXX) -c CRam.cpp -o ram.o -Ofast -Wall 
temperature:
	$(CXX) -c CTemperature.cpp -o temperature.o -Ofast -Wall
swap:
	$(CXX) -c CSwap.cpp -o swap.o -Ofast -Wall  
statusshooter:
	$(CXX) -c CStatusShooter.cpp -o statusshooter.o -Ofast -Wall  
