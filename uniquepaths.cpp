/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m-1+n-1,R=min(m-1,n-1);
        long long C[N+1][R+1];
        for(int i=0; i<=N; i++) C[i][0]=1;
        for(int i=0; i<=R; i++) C[0][i]=0;
        C[0][0]=1;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=R; j++){
                C[i][j]=C[i-1][j-1]+C[i-1][j];
            }
        }
        return (int)C[N][R];
    }
};
