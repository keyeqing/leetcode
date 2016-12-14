//
// Created by keyeqing on 16-12-13.
//

#ifndef ALGORITHM_SOLUTION_475_H
#define ALGORITHM_SOLUTION_475_H

#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution_475 {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int minR = INT_MIN, i = 0, j = 0;
        for (int i = 0; i < houses.size(); i++) {
            int tmp = INT_MAX;
            if(j>0) j--;
            for (; j < heaters.size(); j++) {
                tmp = min(tmp, abs(heaters[j] - houses[i]));
                //cout<<"i:"<<i<<" j:"<<j<<" tmp:"<<tmp<<endl;
                if (heaters[j] > houses[i]) {
                    break;
                }
            }

            minR = max(minR, tmp);
        }
        return minR;
    }
};

void test_475();


#endif //ALGORITHM_SOLUTION_475_H
