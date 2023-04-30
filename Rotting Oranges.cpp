// https://leetcode.com/problems/rotting-oranges/description/

class Solution {
private:
    void bfs(vector<vector<int>>& grid) {
        queue <pair <int, int>> q;
        int m = grid.size(), n = grid[0].size();
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        }

        while (!q.empty()) {
            pair <int, int> p = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int i = p.first + dir[k][0];
                int j = p.second + dir[k][1];
                if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) {
                    q.push(make_pair(i, j));
                    grid[i][j] += grid[p.first][p.second];
                }
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        bfs(grid);
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans = max(ans, grid[i][j]);
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans > 0 ? ans - 2 : 0;
    }
};
