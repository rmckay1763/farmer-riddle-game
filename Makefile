CXX = g++
CPPFLAGS = -c -g -Wall
RM = rm -f

OBJS = BankList.o River.o Farmer.o

run: all
	./driver

all: driver

driver: driver.cpp $(OBJS)
	$(CXX) -o driver $^

Farmer.o: Farmer.h Farmer.cpp River.o
	$(CXX) $(CPPFLAGS) Farmer.cpp

River.o: River.h River.cpp BankList.o
	$(CXX) $(CPPFLAGS) River.cpp

BankList.o: BankList.h BankList.cpp
	$(CXX) $(CPPFLAGS) BankList.cpp

clean:
	$(RM) $(OBJS) driver