
/* Created by keyeqing on 16-11-25.
 *
 * leetcode 253
 *
 * https://leetcode.com/problems/meeting-rooms-ii/
 *
 *
*/

#ifndef ALGORITHM_SOLUTION_253_H
#define ALGORITHM_SOLUTION_253_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}


};

class Solution_253 {
public:

    int minMeetingRooms(vector<Interval> &intervals) {
        map<int,int> count;
        int minRooms=0;
        for (Interval interval:intervals) {
            count[interval.start]++;
            count[interval.end]--;
        }
        int tmp=0;
        for (map<int,int>::iterator it = count.begin();it!=count.end();it++) {
            tmp+=it->second;
            minRooms=max(minRooms,tmp);
        }
        return minRooms;
    }

};


#endif //ALGORITHM_SOLUTION_253_H
