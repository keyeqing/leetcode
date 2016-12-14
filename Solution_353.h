//
// Created by keyeqing on 16-12-7.
//

#ifndef ALGORITHM_SOLUTION_353_H
#define ALGORITHM_SOLUTION_353_H

#include <utility>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    int width;
    int height;
    vector<pair<int, int>> food;
    queue<pair<int,int>> path;

    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->food = food;
        this->width = width;
        this->height = height;
        path.push(make_pair(0,0));
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */


#endif //ALGORITHM_SOLUTION_353_H
