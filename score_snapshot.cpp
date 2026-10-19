// CSCI 2350 - Assignment 2 - Task C
// Name: Mason Wilkes
// R number: TODO
#include <iostream>

int maxScore(const int* scores, int count);
bool updateScore(int* scores, int count, int index, int replacement);

int* cloneScores(const int* source, int count) {
    // Write this function using the Task C contract in the handout.
    // Replace the following stub.
    if (source == nullptr || count <= 0) {
        return nullptr;
    }
    
    int* copy = new int [count];

    for (int i = 0; i < count; ++i) {
        copy[i] = source[i];
    }
    return copy;
}

void curveScores(int* scores, int count) {
    // Write this function using the Task C contract in the handout.
    // Replace the following stub.
    if (scores == nullptr || count <= 0) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        scores[i] += 5;

        if (scores[i] > 100) {
            scores[i] = 100;
        }
    }
}


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
    int* snapshot = nullptr;

    // Use your completed Task B main as the starting point.
    // Add the snapshot and curve required by Task C.
    // Remove these unused-variable lines when you write the program.
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

    snapshot = cloneScores(working, count);

    bool correctionApplied = updateScore(working, count, index, replacement);

    std::cout << std::boolalpha;
    std::cout << "correction applied: " << correctionApplied << '\n';
    std::cout << "working scores: ";
    printScores(working, count);

    std::cout << "working max: " << maxScore(working, count) << '\n';

    curveScores(working, count);

    std::cout << "curved scores: ";
    printScores(working, count);

    std::cout << "curved max: " << maxScore(working, count) << '\n';

    delete[] working;
    working = nullptr;

    std::cout << "snapshot after working release: ";
    printScores(snapshot, count);

    std::cout << "snapshot max: " << maxScore(snapshot, count) << '\n';

    delete[] snapshot;
    snapshot = nullptr;

    std::cout << "owners cleared: " << (working == nullptr && snapshot == nullptr) << '\n';

    return 0;
}