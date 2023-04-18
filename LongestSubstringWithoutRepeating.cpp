/*

https://leetcode.com/problems/longest-substring-without-repeating-characters/

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


// FIRST APPROACH: Brute force offcourse

// SECOND APPROACH: Two pointer [Time: O(2*n), Space: O(n)]
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

// THIRD APPROACH: Optimal two pointer [Time: O(n), Space: O(n)]
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int characterPosition[256];
        for (int i = 0; i < 256; i++) {
            characterPosition[i] = -1;
        }
        int ans = 0, current = 0, prev = -1;
        for (int i = 0; i < s.size(); i++) {
            if (characterPosition[int(s[i])] == -1) {
                current++;
            } else {
                if (characterPosition[int(s[i])] >= prev) {
                    current = i - characterPosition[int(s[i])];
                    prev = characterPosition[int(s[i])] + 1;
                } else {
                    current++;
                }
            }
            characterPosition[int(s[i])] = i;
            ans = max(ans, current);
        }
        return ans;
    }
};


// Same as Third Approach but less code
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> um;
        int initialPos = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (um[s[i]] > 0) {
                initialPos = max(initialPos, um[s[i]]);
            }
            ans = max(ans, i - initialPos + 1);
            um[s[i]] = i + 1;
        }
        return ans;
    }
};
