# Makefile

CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

SRC = src/Graph.cpp src/VehicleManager.cpp src/TrafficRouter.cpp src/main.cpp
OUT = traffic_system

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
