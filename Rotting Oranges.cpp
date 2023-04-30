// https://leetcode.com/problems/rotting-oranges/description/

class Solution {
private:
    int bfs(vector<vector<int>>& grid) {
        queue <pair <int, int>> q;
        int m = grid.size(), n = grid[0].size(), cnt = 0, ans = 0;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                } else if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }

        while (!q.empty()) {
            pair <int, int> p = q.front();
            ans = max(ans, grid[p.first][p.second]);
            q.pop();
            for (int k = 0; k < 4; k++) {
                int i = p.first + dir[k][0];
                int j = p.second + dir[k][1];
                if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) {
                    q.push(make_pair(i, j));
                    grid[i][j] += grid[p.first][p.second];
                    cnt--;
                }
            }
        }
        return cnt > 0 ? -1 : ans;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = bfs(grid);
        return ans <= 0 ? ans : ans - 2;
    }
};
