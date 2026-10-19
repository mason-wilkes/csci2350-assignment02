// Supplied Task A checks. Each check group starts with fresh arrays.
#include <iostream>
int maxScore(const int* scores, int count);
bool updateScore(int* scores, int count, int index, int replacement);

bool report(const char* name, bool ok) {
    std::cout << (ok ? "PASS " : "FAIL ") << name << '\n';
    return ok;
}

int main() {
    bool all = true;
    int normal[] = {72, 95, 55, 80};
    if (!report("A01 maximum", maxScore(normal, 4) == 95)) all = false;
    int one[] = {0};
    int negative[] = {-9, -3, -12};
    if (!report("A02 maximum boundaries",
        maxScore(nullptr, 4) == -1 && maxScore(one, 0) == -1 &&
        maxScore(one, -1) == -1 && maxScore(one, 1) == 0 &&
        maxScore(negative, 3) == -3)) all = false;
    int middle[] = {10, 20, 30};
    if (!report("A03 one update",
        updateScore(middle, 3, 1, 88) && middle[0] == 10 &&
        middle[1] == 88 && middle[2] == 30)) all = false;
    // These two accepted updates are consecutive on the same array.
    int edge[] = {10, 20, 30};
    if (!report("A04 update boundaries",
        updateScore(edge, 3, 0, 0) && updateScore(edge, 3, 2, 100) &&
        edge[0] == 0 && edge[1] == 20 && edge[2] == 100)) all = false;
    int rejected[] = {10, 20, 30};
    if (!report("A05 rejected updates",
        !updateScore(nullptr, 3, 0, 50) &&
        !updateScore(rejected, 0, 0, 50) &&
        !updateScore(rejected, -1, 0, 50) &&
        !updateScore(rejected, 3, -1, 50) &&
        !updateScore(rejected, 3, 3, 50) &&
        !updateScore(rejected, 3, 1, -1) &&
        !updateScore(rejected, 3, 1, 101) &&
        rejected[0] == 10 && rejected[1] == 20 && rejected[2] == 30)) all = false;
    return all ? 0 : 1;
}
