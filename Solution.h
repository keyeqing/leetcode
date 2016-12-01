//
// Created by keyeqing on 16-11-24.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H

#include <vector>
#include <cstdio>
#include <iostream>
#include <unordered_set>

using namespace std;

class Node {
public:
    vector<Node *> children;
    Node(){
        children={2, NULL};
    }
};

class TrieTree {
public:
    Node *root = new Node();
    TrieTree(vector<int> &num) {
        for (int i = 0; i < num.size(); i++) {
            Node *p = root;
            for (int j = 31; j >= 0; j--) {
                int index = ((num[i]>>j)&1);
                if(j==0){
                    cout<<index<<endl;
                }

                if ((p->children)[index] == NULL) {
                    (p->children)[index] = new Node();
                }
                p = (p->children)[index];
            }
        }
    }
    int findMaxNum(int num){
        Node *p=root;
        int max=0;
        for (int i = 31; i >= 0; i--) {
            unsigned b = (num>>i)&1;
            b=!b;
            if(i==0){
                cout<<b<<endl;
            }
            if((p->children)[b]== NULL){
               b=!b;
            }
            p=(p->children)[b];
            max|=(b<<i);
        }
        return max^num;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        TrieTree *tree = new TrieTree(nums);
        int maxXOR=0;
        for (int i = 0; i < nums.size(); ++i) {
            maxXOR=max(maxXOR,tree->findMaxNum(nums[i]));
        }
        return maxXOR;
    }
    int findMaximumXORV2(vector<int> &nums) {
        int flag=0;
        int maxXOR=0;
        for(int i=31;i>=0;i--){
            unordered_set<int> prefix;
            flag=flag|(1<<i);
            for (int j = 0; j < nums.size(); ++j) {
                prefix.insert(nums[j]&flag);
            }
            int tmp = maxXOR|(1<<i);
            for (int pre:prefix) {
                if (prefix.find(tmp^pre)!=prefix.end()){
                    maxXOR=tmp;
                    break;
                }
            }
        }
        return maxXOR;

    }
};


#endif //ALGORITHM_SOLUTION_H
