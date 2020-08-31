/*

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

*/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int ans1=0,ans2=0;
        int n=s.length();
        for(int i=0; i<n; i++){
            int k=0;
            while(1){
                if(i-k>=0 && i+k<n && s[i-k]==s[i+k]){
                    if(ans2-ans1+1<2*k+1){
                        ans2=i+k;
                        ans1=i-k;
                    }
                }
                else break;
                k++;
            }
        }
        
        for(int i=0; i<n-1; i++){
            int k=0;
            if(s[i]==s[i+1]){
                while(1){
                    if(i-k>=0 && i+1+k<n && s[i-k]==s[i+1+k]){
                        if(ans2-ans1+1<2*k+2){
                            ans2=i+1+k;
                            ans1=i-k;
                        }
                    }
                    else break;
                    k++;
                }
            }
        }
        
        string ans=s.substr(ans1, ans2-ans1+1);
        return ans;
    }
};
