/*

In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.

*/

// FIRST APPROACH: using a queue
class Solution {
public:
  
    int N;int M;
    vector<vector<int>>arr;
    int ans=0;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    void bfs(){
        queue<pair<int,int>>q;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j]==2)
                    q.push({i,j});
            }
        }
        q.push({-1,-1});
   
        while(!q.empty()){
            bool flag=false;
            pair<int,int> temp={-1,-1};
            while(q.front()!=temp){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int dx=x+dir[k][0];
                    int dy=y+dir[k][1];
                    if(dx<0 || dx>=N || dy<0 || dy>=M)
                        continue;
                    if(arr[dx][dy]==1){
                        q.push({dx,dy});
                        flag=true;
                        arr[dx][dy]=2;
                    }
                }
            }
            q.pop();
            if(!q.empty())
                q.push({-1,-1});
            if(flag==true)
                ans++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        N=n;M=m;
        arr=grid;
        bfs();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1)
                    return -1;
            }
        }
        return ans;
    }
};


// SECOND APPROACH: Same approach as previous one but elegent
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) rotten.push({i, j});
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k; 
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) days++;
        }
        
        return tot == cnt ? days : -1;
    }
