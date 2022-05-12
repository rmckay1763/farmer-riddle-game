# Makefile for the farmer riddle game.

CXX = g++
CPPFLAGS = -c -g -Wall
RM = rm -f

OBJS = BankList.o River.o Farmer.o

# target to execute the program
run: all
	./driver

# target to build the program
all: driver

# compiles driver and links with objects
driver: driver.cpp $(OBJS)
	$(CXX) -o driver $^

# compile the Farmer class
Farmer.o: Farmer.h Farmer.cpp River.o
	$(CXX) $(CPPFLAGS) Farmer.cpp

# compile the River class
River.o: River.h River.cpp BankList.o
	$(CXX) $(CPPFLAGS) River.cpp

# compile the BankList class
BankList.o: BankList.h BankList.cpp
	$(CXX) $(CPPFLAGS) BankList.cpp

# remove all object files and the executable
clean:
	$(RM) $(OBJS) driver