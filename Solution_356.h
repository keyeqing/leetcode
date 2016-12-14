//
// Created by keyeqing on 16-12-2.
//

#ifndef ALGORITHM_SOLUTION_356_H
#define ALGORITHM_SOLUTION_356_H

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution_356 {
public:

    bool isReflected(vector<pair<int, int>> &points) {
        if (points.size() == 0) return true;
        long maxV = INT_MIN, minV = INT_MAX;
        unordered_map<int, unordered_set<int>> m;
        for (int i = 0; i < points.size(); ++i) {
            minV=min(minV,(long)points[i].first);
            maxV=max(maxV,(long)points[i].first);
            m[points[i].first].insert(points[i].second);
        }

        long x2 = maxV+minV;
        for (int j = 0; j < points.size(); ++j) {
            unordered_set<int> s =  m[x2-points[j].first];
            if(s.find(points[j].second)==s.end()){
                return false;
            }
        }
        return true;
    }
};


#endif //ALGORITHM_SOLUTION_356_H
