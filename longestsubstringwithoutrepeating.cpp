/*

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,curr=0,prev=0;
        int arr[256]={0};
        
        for(int i=0; i<s.size(); i++){
            arr[s[i]-NULL]++;
            curr++;
            if(arr[s[i]-NULL]>1){
                while(arr[s[i]-NULL]>1){
                    arr[s[prev]-NULL]--;
                    prev++;
                    curr--;
                }
            }
            else{
                ans=max(curr,ans);
            }
        }
        return ans;
    }
};
