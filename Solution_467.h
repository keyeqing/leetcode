//
// Created by 柯叶青 on 2016/12/8.
//

#ifndef ALGORITHM_SOLUTION_467_H
#define ALGORITHM_SOLUTION_467_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution_467 {

public:
    int findSubstringInWraproundString(string p) {
        if (p.size() == 0) return 0;
        vector<int> dict(26, 0);
        int start = 0, i = 0;
        while (i <= p.size()) {
            while (i<p.size() && (i==0 || i - 1 >= 0 && (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25))) i++;
            cout << i << endl;
            for (int j = 0; j < 26; j++) {
                dict[(p[start] - 'a' + j) % 26] = max(dict[(p[start] - 'a' + j) % 26], i - start - j);
            }
            start = i;
            i++;
        }
        int count = 0;
        for (int j = 0; j < 26; j++) {
            count += dict[j];
        }
        return count;

    }
};


#endif //ALGORITHM_SOLUTION_467_H
