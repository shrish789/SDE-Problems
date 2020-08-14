/*

There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.

What is the maximum number of meetings that can be accommodated in the meeting room?

Input:
The first line of input consists number of the test cases. The description of T test cases is as follows:
The first line consists of the size of the array, second line has the array containing the starting time of all the meetings each separated by a space, i.e., S [ i ]. And the third line has the array containing the finishing time of all the meetings each separated by a space, i.e., F [ i ].

Output:
In each separate line print the order in which the meetings take place separated by a space.

Constraints:
1 ≤ T ≤ 70
1 ≤ N ≤ 100
1 ≤ S[ i ], F[ i ] ≤ 100000

Example:
Input:
2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252  

Output:
1 2 4 5
6 7 1

*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int, pair<int, int>>> v(n);
    for(int i=0; i<n; i++) cin>>v[i].second.first;
    for(int i=0; i<n; i++) cin>>v[i].first, v[i].second.second=i;
    
    sort(v.begin(), v.end());
    vector <int> ans;
    int prev;
    for(int i=0; i<n; i++){
        if(i==0){
            prev=v[i].first;
            ans.push_back(v[i].second.second);
            continue;
        }
        if(v[i].second.first>=prev){
            ans.push_back(v[i].second.second);
            prev=v[i].first;
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]+1<<" ";
    }
    cout<<"\n";
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
