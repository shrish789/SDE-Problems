/*

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]


*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> v1;
        if(numRows==0) return v;
        v1.push_back(1);
        v.push_back(v1);
        if(numRows==1) return v;
        v1.push_back(1);
        v.push_back(v1);
        for(int i=0; i<numRows-2; i++){
            v1.clear();
            v1.push_back(1);
            for(int j=0; j<v.back().size()-1; j++){
                v1.push_back(v.back()[j]+v.back()[j+1]);
            }
            v1.push_back(1);
            v.push_back(v1);
        }
        return v;
    }
};
