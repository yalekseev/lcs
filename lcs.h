#pragma once

#include <algorithm>
#include <iterator>
#include <vector>

namespace util {

/* O(mn) */
template <typename Iterator1, typename Iterator2>
int longest_common_subsequence(Iterator1 begin1, Iterator1 end1, Iterator2 begin2, Iterator2 end2) {
    auto size1 = std::distance(begin1, end1);
    auto size2 = std::distance(begin2, end2);

    std::vector<std::vector<int>> t(size1 + 1);
    for (auto &r : t) {
        r.resize(size2 + 1, 0);
    }

    auto i = 1;
    for (auto it1 = begin1; it1 != end1; ++it1, ++i) {
        auto j = 1;
        for (auto it2 = begin2; it2 != end2; ++it2, ++j) {
            if (*it1 == *it2) {
                t[i][j] = t[i - 1][j - 1] + 1;
            } else {
                t[i][j] = std::max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    return t[size1][size2];
}

} // namespace util
