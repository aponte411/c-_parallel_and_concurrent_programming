# Thread vs Process Demo 
CXX = g++
CXXFLAGS = -pthread -Wall -std=c++11
TARGET = thread_and_process
SRC = single_process_multiple_threads.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)

.PHONY: exec_sched
exec_sched:
	$(CXX) $(CXXFLAGS) execution_scheduling.cpp -o exec_sched
