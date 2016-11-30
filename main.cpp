#include <iostream>
#include <map>
#include "Solution_267.h"

using namespace std;
int main() {
    //std::cout << "Hello, World!" << std::endl;
    Solution_267 solution267;
    vector<string> res = solution267.generatePalindromes("abccbcc");
    for (string s:res){
        cout<<s<<endl;
    }
    return 0;
}