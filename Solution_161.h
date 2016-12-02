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
        vector <vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
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

    bool isOneEditDistance_v2(string s, string t) {
        int m = s.size(), n = t.size();
        if (m == n || abs(m - n) == 1) {
            int count = 0;
            int i = 0, j = 0;
            while (i < m && j < n) {
                if (s[i] != t[j]) {
                    count++;
                    if (count > 1) return false;
                    if (m >= n) {
                        i++;
                    }
                    if (n >= m) {
                        j++;
                    }
                } else {
                    i++;
                    j++;
                }
            }

            if (count == 1 || abs(m - n) == 1 && count == 0 && (m == 0 || n == 0 || j == m - 1 || i == n - 1)) {
                return true;
            } else {
                return false;
            }
        }
        return false;

    }

    bool isOneEditDistance_v3(string s, string t) {
        for (int i = 0; i < min(s.size(), t.size()); ++i) {
            if (s[i] != t[i]) {
                if (s.size() == t.size()) {
                    return s.substr(i + 1) == t.substr(i + 1);
                } else if (s.size() > t.size()) {
                    return s.substr(i + 1) == t.substr(i);
                } else {
                    return s.substr(i) == t.substr(i + 1);
                }
            }
        }
        return abs(s.size() - t.size()) == 1;
    }

    >>>>>>> 1f50d521d463fa23d2363f35057dc97296255dd5
};

bool test_161();

#endif //ALGORITHM_SOLUTION_161_H
