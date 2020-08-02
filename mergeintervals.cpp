/*

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

class Solution {
public:
    int max(int a, int b){
        if(a>b) return a;
        return b;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        if(intervals.empty()) return v;
        sort(intervals.begin(), intervals.end());
        v.push_back(intervals[0]);
        vector<int> v1;
        
        for(int i=1; i<intervals.size(); i++){
            v1=intervals[i];
            if(v1[0]<=v.back()[1]) v.back()[1]=max(v1[1],v.back()[1]);
            else v.push_back(v1);
        }
        return v;
    }
};
