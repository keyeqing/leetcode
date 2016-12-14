//
// Created by keyeqing on 16-12-5.
//

#ifndef ALGORITHM_SOLUTION_456_H
#define ALGORITHM_SOLUTION_456_H

#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution_456 {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> ss;
        int third=INT_MIN;
        for (int i = nums.size()-1; i >= 0; i--) {
            if(nums[i]<third) return true;
            if(!ss.empty() && nums[i]>ss.top()){
                third=ss.top();
                ss.pop();
            }
            ss.push(nums[i]);
        }
        return false;
    }

    bool find132parttern_v2(vector<int>& nums){
        int minV=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>minV){
                for (int j = i+1; j < nums.size(); ++j) {
                    if(nums[j]<nums[i] && nums[j]>minV){
                        return true;
                    }
                }
            }
            minV = min(minV,nums[i]);
        }
        return false;
    }
};


#endif //ALGORITHM_SOLUTION_456_H
