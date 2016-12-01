//
// Created by keyeqing on 16-11-28.
//

#ifndef ALGORITHM_SOLUTION_261_H
#define ALGORITHM_SOLUTION_261_H

#include <utility>
#include <vector>

using namespace std;
class Solution_261 {
public:
    int find(vector<int> &root,int i){
        if(root[i]==-1) return i;
        int parent = find(root,root[i]);
        root[i] = parent;
        return parent;
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> root(n,-1);
        vector<int> size(n,1);
        for(pair<int,int> edge:edges){
            int root1=find(root,edge.first);
            int root2=find(root,edge.second);
            if(root1==root2)
                return false;
            if(size[root1]>size[root2]){
                root[root2]=root1;
            }else {
                root[root1]=root2;
                if(size[root1]=size[root2]){
                    size[root2]++;
                }
            }
        }
        return edges.size()==n-1;
    }
};


#endif //ALGORITHM_SOLUTION_261_H
