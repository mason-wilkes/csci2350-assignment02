// CSCI 2350 - Assignment 2 - Task A
// Name: Mason Wilkes
// R number: TODO
// Keep these function headers. Do not add main to this file.

int maxScore(const int* scores, int count) {
    // Write this function using the Task A contract in the handout.
    // Replace the following stub.
    if (scores == nullptr || count <= 0) {
        return -1;
    }

    int largest = scores[0];

    for (int i = 1; i < count; ++i) {
        if (scores[i] > largest) {
            largest = scores[i];
        }
    }
    return largest;
}

bool updateScore(int* scores, int count, int index, int replacement) {
    // Write this function using the Task A contract in the handout.
    // Replace the following stub.
    if (scores == nullptr || count <= 0 || index < 0 || index >= count || replacement < 0 || replacement > 100) {
        return false;
    }

    scores[index] = replacement;
    return true;
}