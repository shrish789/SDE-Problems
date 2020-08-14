/*

Problem Description

Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.



Problem Constraints
1 <= N <= 10

0 <= A[i][0] < A[i][1] <= 2 * 109



Input Format
The only argument given is the matrix A.



Output Format
Return the minimum number of conference rooms required so that all meetings can be done.



*/

// Priority queue Solution

bool comp(vector<int> A, vector<int> B){
return A[0]<B[0];
}
int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end(),comp);
    priority_queue <int, vector<int>, greater<int> > pq; 
    pq.push(A[0][1]);
    int ans=1;
    for(int i=1;i<A.size();i++){
        if(A[i][0]>=pq.top()){
            pq.pop();
        }
        else{ans++;}
        pq.push(A[i][1]);
    }
    return ans;
}


// Array based solution

int Solution::solve(vector<vector<int> > &a) {
    int n = a.size();
    if(n <= 1)
        return n;
        
    vector<pair<int, int>> arr;
    for(int i=0; i<n; i++){
        arr.push_back({a[i][0], 1});    //mark arrival time as 1
        arr.push_back({a[i][1], 0});    //mark departure time as 0
    }
    sort(arr.begin(), arr.end());
    
    int res = 0, curr = 0, i = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i].second == 1){     //count max no of rooms we need
            curr++;
            res = max(curr, res);
        }
        else{
            curr--;
        }
    }
    return res;
}
