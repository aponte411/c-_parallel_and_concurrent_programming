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

.PHONY: clean_exec_sched
clean_exec_sched:
	rm -f exec_sched



.PHONY: mutex_w_guard
mutex_w_guard:
	$(CXX) $(CXXFLAGS) mutex_with_guard.cpp -o mutex_w_guard

.PHONY: clean_mutex_w_guard
clean_mutex_w_guard:
	rm -f mutex_w_guard


