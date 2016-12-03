//
// Created by 柯叶青 on 2016/12/3.
//

#ifndef ALGORITHM_SOLUTION_163_H
#define ALGORITHM_SOLUTION_163_H

#include <vector>
#include <string>

using namespace std;

class Solution_163 {
public:
    string genRange(int start, int end) {
        if (start == end) return to_string(start);
        return to_string(start) + "->" + to_string(end);
    }

    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        vector<string> res;
        for (int num:nums) {
            if (num > lower) {
                res.push_back(genRange(lower, num - 1));
            }
            if (num == upper) return res;
            lower = max(num, num + 1);

        }
        if (upper >= lower) {
            res.push_back(genRange(lower, upper));
        }
        return res;
    }
};


#endif //ALGORITHM_SOLUTION_163_H
