#include <iostream>
#include "Solution_253.h"
#include "Solution_161.h"
#include "Solution_417.h"
#include "Solution_356.h"

using namespace std;

int main() {
    cout<<"Hello World "<<endl;
    Solution_356 solution356;
    vector<pair<int,int>> points;
    points.push_back(make_pair(16,1));
    points.push_back(make_pair(-16,1));
    points.push_back(make_pair(16,1));
    cout << solution356.isReflected(points) << endl;
    //cout << test_161() << endl;
}
