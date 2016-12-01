//
// Created by keyeqing on 16-11-28.
//

#ifndef ALGORITHM_SOLUTION_277_H
#define ALGORITHM_SOLUTION_277_H

bool knows(int a, int b);

class Solution_277 {
public:
    int findCelebrity(int n) {
        int c=-1;
        for(int i=0;i<n;i++){
            if(i==0 || !knows(i,c)){
                c=i;
            }
        }
        for(int i=0;i<n;i++) {
            if(i<c&&(!knows(i,c)||knows(c,i)) || c>i && knows(c,i)){
                return -1;
            }
        }
        return c;
    }
};


#endif //ALGORITHM_SOLUTION_277_H
