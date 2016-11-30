//
// Created by 柯叶青 on 2016/11/30.
//

#ifndef LEETCODE_SOLUTION_267_H
#define LEETCODE_SOLUTION_267_H

#include <map>
#include <vector>
#include <string>


using namespace std;


class Solution_267 {
public:
    vector<string> res;
    int n;

    void dfs(map<char, int> &m, string tmp, int index) {
        if (index == n / 2) {
            res.push_back(tmp);
        } else {
            for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
                int num = it->second;
                if (num >= 2) {
                    tmp[index] = it->first;
                    tmp[n - index - 1] = it->first;
                    m[it->first] -= 2;
                    dfs(m, tmp, index + 1);
                    m[it->first] += 2;
                }
            }
        }
    }

    vector<string> generatePalindromes(string s) {
        n = s.size();
        map<char, int> m;
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
        }
        char mid;
        int count = 0;
        for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
            if ((it->second) % 2 == 1) {
                count++;
                mid = it->first;
            }
        }
        if (n % 2 == 0 && count > 0 || n % 2 == 1 && count > 1) return res;
        string tmp(n, ' ');
        if (count == 1) {
            tmp[n / 2] = mid;
            m[mid]--;
        }
        dfs(m, tmp, 0);
        return res;
    }
};


#endif //LEETCODE_SOLUTION_267_H
