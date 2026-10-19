CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

.PHONY: help list all clean 1 2 3
help: list
list:
	@echo "make 1: build and check the Task A functions"
	@echo "make 2: build and check the Task B working-array program"
	@echo "make 3: build and check the Task C snapshot program"
all: score_functions_check score_working score_snapshot
1: score_functions_check
	@./score_functions_check
2: score_working
	@bash support/run_cases.sh ./score_working expected/working
3: score_snapshot
	@bash support/run_cases.sh ./score_snapshot expected/snapshot
score_functions_check: score_functions.cpp support/task_a_driver.cpp
	$(CXX) $(CXXFLAGS) score_functions.cpp support/task_a_driver.cpp -o score_functions_check
score_working: score_functions.cpp score_working.cpp
	$(CXX) $(CXXFLAGS) score_functions.cpp score_working.cpp -o score_working
score_snapshot: score_functions.cpp score_snapshot.cpp
	$(CXX) $(CXXFLAGS) score_functions.cpp score_snapshot.cpp -o score_snapshot
clean:
	$(RM) score_functions_check score_functions_check.exe score_working score_working.exe score_snapshot score_snapshot.exe *.o *.obj
