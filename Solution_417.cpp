//
// Created by keyeqing on 16-11-30.
//

#include <iostream>
#include "Solution_417.h"

int test() {
    //[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
    Solution_417 solution;
    vector<vector<int>> matrix={{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<pair<int,int>> res=solution.pacificAtlantic(matrix);
    for (pair<int,int> p:res) {
        cout<<p.first<<" "<<p.second<<endl;
    }

    return 0;
}