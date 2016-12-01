//
// Created by keyeqing on 16-12-1.
//

#ifndef ALGORITHM_SOLUTION_161_H
#define ALGORITHM_SOLUTION_161_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution_161 {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (abs(m - n) > 1) return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 1 || i == 1 && j == 0) {
                    dp[i][j] = true;
                } else if (i > 0 && j > 0) {
                    dp[i][j] = (s[i - 1] == t[j - 1] && dp[i - 1][j - 1] ||
                                s[i - 1] != t[j - 1] && ((s.substr(0, i - 1) == t.substr(0, j - 1)) ||
                                                         (s.substr(0, i) == t.substr(0, j - 1)) ||
                                                         (s.substr(0, i - 1) == t.substr(0, j))));
                    string ss = s.substr(0, i - 1);
                    string tt = t.substr(0, j - 1);
                    cout << i << " " << j << " " << ss << " " << tt << " " << (ss == tt) << " "
                         << (s[i - 1] != t[j - 1]) << " " << dp[i][j] << endl;
                }
            }
        }
        return dp[m][n];
    }
};

bool test_161();

#endif //ALGORITHM_SOLUTION_161_H
