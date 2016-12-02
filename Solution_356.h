//
// Created by keyeqing on 16-12-2.
//

#ifndef ALGORITHM_SOLUTION_356_H
#define ALGORITHM_SOLUTION_356_H

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution_356 {
public:
    static int cmp(pair<int, int> &p1, pair<int, int> &p2) {
        return p1.first < p2.first;
    }

    bool isReflected(vector<pair<int, int>> &points) {
        if (points.size() == 0) return false;
        sort(points.begin(), points.end(), cmp);
        unordered_map<int, int> m;
        for (int i = 0; i < points.size(); ++i) {
            if (m.find((points[i]).first) == m.end()) {
                m[points[i].first] = i;
            }
        }
        int i = 0, end = points.size() - 1;
        double x2 = ((double) points[i].first + (double) points[end].first);
        while (i < end) {
            int start = m[points[end].first];
            for (int j = start; j <= end; j++, i++) {
                if (x2 != (double) points[i].first + (double) points[j].first ||
                    points[i].second != points[j].second)
                    return false;
            }
            end = start - 1;
        }
        return true;
    }
};


#endif //ALGORITHM_SOLUTION_356_H
