#include "lcs.h"

#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = { 1, 2, 3, 4, 1 };
    std::vector<int> b = { 3, 4, 1, 2, 1, 3 };
    std::cout << util::longest_common_subsequence(a.begin(), a.end(), b.begin(), b.end()) << std::endl;

    return 0;
}
