//
// Created by 柯叶青 on 2016/12/3.
//

#ifndef ALGORITHM_SOLUTION_379_H
#define ALGORITHM_SOLUTION_379_H

#include <queue>
#include <map>

using namespace std;
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    vector<int> avaliable;
    vector<int> isvaliable;
    int idx;
    PhoneDirectory(int maxNumbers) {
        for(int i=0;i<maxNumbers;i++){
            avaliable.push_back(maxNumbers-1-i);
            isvaliable.push_back(1);
        }
        idx=maxNumbers-1;
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        //cout<<"get, idx:"<<idx<<endl;
        if(idx<0) return -1;
        isvaliable[avaliable[idx]]=0;
        return avaliable[idx--];
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return number<isvaliable.size() && isvaliable[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        //cout<<"release, idx:"<<idx<<isvaliable[number]<<endl;
        if(number<isvaliable.size() && !isvaliable[number]){
            isvaliable[number]=1;
            //cout<<"release num:"<<number<<endl;
            avaliable[++idx]=number;
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */


#endif //ALGORITHM_SOLUTION_379_H
