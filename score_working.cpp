// CSCI 2350 - Assignment 2 - Task B
// Name: Mason Wilkes
// R number: TODO
#include <iostream>

int maxScore(const int* scores, int count);
bool updateScore(int* scores, int count, int index, int replacement);


void printScores(const int* scores, int count) {
    for (int i = 0; i < count; ++i) {
        if (i > 0) std::cout << ' ';
        std::cout << scores[i];
    }
    std::cout << '\n';
}


int main() {
    int count = 0;
    int* working = nullptr;

    // Write the Task B program here. The handout gives the input,
    // error messages, report, and cleanup requirements.
    // Remove these two unused-variable lines when you write the program.
    if (!(std::cin >> count) || count < 1 || count > 20) {
        std::cout << "Invalid score count\n";
        return 0;
    }

    working = new int[count]{};

    for (int i = 0; i < count; ++i) {
        if (!(std::cin >> working[i]) || working[i] < 0 || working[i] > 100) {
            std::cout << "Invalid score data\n";
            delete[] working;
            working = nullptr;
            return 0;
        }
    }
    
    int index = 0;
    int replacement = 0;

    if (!(std::cin >> index >> replacement)) {
        std::cout << "Invalid correction data\n";
        delete[] working;
        working = nullptr;
        return 0;
    }

    bool correctionApplied = updateScore(working, count, index, replacement);
    
    std::cout << std::boolalpha;
    std::cout << "correction applied: " << correctionApplied << '\n';
    std::cout << "working scores: ";
    printScores(working, count);
    std::cout << "working max: " << maxScore(working, count) << '\n';
    
    delete[] working;
    working = nullptr;

    std::cout << "owner cleared: " << (working == nullptr) << '\n';

    return 0;
}
