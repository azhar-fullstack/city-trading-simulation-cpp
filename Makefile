# Makefile for City Trading Simulation (C++)

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2
TARGET = riversystem
SOURCES = main.cpp Boat.cpp City.cpp Inventory.cpp Product.cpp RiverSystem.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET) *.o *.exe

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run 