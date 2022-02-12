/*
https://leetcode.com/problems/search-a-2d-matrix/

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m * n - 1, mid;
        
        while (low <= high) {
            mid = (low + high) / 2;
            if (target == matrix[mid / n][mid % n]) {
                return true;
            } else if (target < matrix[mid / n][mid % n]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};
