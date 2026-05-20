CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = src/Person.cpp src/Student.cpp src/Admin.cpp src/Item.cpp \
       src/ElectronicItem.cpp src/DocumentItem.cpp src/PersonalItem.cpp \
       src/Transaction.cpp src/Claim.cpp src/Handover.cpp src/Reward.cpp \
       src/SearchLog.cpp src/Report.cpp src/FileManager.cpp src/MatchEngine.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
EXEC = CampusTrace

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o *.o $(EXEC)
