//
// Created by keyeqing on 16-11-30.
//

#ifndef ALGORITHM_SOLUTION_417_H
#define ALGORITHM_SOLUTION_417_H

#include <vector>

using namespace std;

/*
 *
 *   Pacific ~   ~   ~   ~   ~
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic
 *
 * */

class Solution_417 {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<int>> matrix;
    int m;
    int n;

    void dfs(vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            if (dx[k] + i < m && dx[k] + i >= 0 && dy[k] + j < n && dy[k] + j >= 0 && !visited[dx[k] + i][dy[k] + j] &&
                matrix[dx[k] + i][dy[k] + j] >= matrix[i][j]) {
                dfs(visited, dx[k] + i, dy[k] + j);
            }
        }
    }

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
        this->matrix = matrix;
        vector<pair<int, int>> res;
        m = matrix.size();
        if (m == 0) return res;
        n = matrix[0].size();
        vector<vector<bool>> pVisited(m, vector<bool>(n, false));
        vector<vector<bool>> aVisited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(pVisited, i, 0);
            dfs(aVisited, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(pVisited, 0, j);
            dfs(aVisited, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pVisited[i][j] && aVisited[i][j]) {
                    res.push_back(make_pair(i, j));
                }
            }
        }
        return res;

    }

};

int test_417();


#endif //ALGORITHM_SOLUTION_417_H
