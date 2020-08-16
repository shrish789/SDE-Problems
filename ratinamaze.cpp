/*

Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (n-1, n-1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and cannot be crossed while value 1 at a cell in the matrix represents that it can be travelled through.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line contains an integer N denoting the size of the square matrix. The next line contains N*N space separated values of the matrix m where 0's represents blocked paths and 1 represent valid paths.

Output:
For each test case, the output will be space separated sorted strings denoting all directions, which the rat could take to reach the destination. Print -1 if no such path exists.

User Task:
Your task is to complete the function printPath() which returns a sorted array of strings denoting all the possible paths which the rat can take to reach the destination at (n-1, n-1). If no such path exists the function should return an empty array.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L*X), L = length of the path, X = number of paths.


Constraints:
1 <= T <= 100
2 <= N <= 5
0 <= matrix[i][j] <= 1

Example
Input:
3
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1
2
1 0 1 0 

Output:
DRDDRR
DDRDRR DRDDRR
-1

Explanation:
Testcase 2: The given input is in the form
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
For the above matrix the rat can reach the destination at (3, 3) from (0, 0) by two paths ie DRDDRR and DDRDRR when printed in sorted order we get DDRDRR DRDDRR.

*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5

void findpath(int m[MAX][MAX], bool vis[MAX][MAX], int x, int y, int n, string str, vector<string> &v);

vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    bool vis[MAX][MAX]={0};
    string str="";
    vector<string>v;
    if(m[0][0]==0) return v;
    findpath(m, vis, 0, 0, n, str, v);
    if(v.size()!=0) sort(v.begin(), v.end());
    return v;
}

void findpath(int m[MAX][MAX], bool vis[MAX][MAX], int x, int y, int n, string str, vector<string> &v){
    if(x==n-1 && y==n-1){
        v.push_back(str);
        return;
    }
    vis[x][y]=1;
    if(x+1<n && m[x+1][y] && !vis[x+1][y]){
        str+='D';
        findpath(m, vis, x+1, y, n, str, v);
        vis[x+1][y]=0;
        str.pop_back();
    }
    if(y+1<n && m[x][y+1] && !vis[x][y+1]){
        str+='R';
        findpath(m, vis, x, y+1, n, str, v);
        vis[x][y+1]=0;
        str.pop_back();
    }
    if(x-1>=0 && m[x-1][y] && !vis[x-1][y]){
        str+='U';
        findpath(m, vis, x-1, y, n, str, v);
        vis[x-1][y]=0;
        str.pop_back();
    }
    if(y-1>=0 && m[x][y-1] && !vis[x][y-1]){
        str+='L';
        findpath(m, vis, x, y-1, n, str, v);
        vis[x][y-1]=0;
        str.pop_back();
    }
}
