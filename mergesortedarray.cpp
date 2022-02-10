/*

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
 

Constraints:
-> -10^9 <= nums1[i], nums2[i] <= 10^9
-> nums1.length == m + n
-> nums2.length == n

*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n;
        while (m >= 1 && n >= 1) {
            if (nums1[m - 1] >= nums2[n - 1]) {
                nums1[--k] = nums1[--m];
            } else {
                nums1[--k] = nums2[--n];
            }
        }
        while (m >= 1) {
            nums1[--k] = nums1[--m];
        }
        while (n >= 1) {
            nums1[--k] = nums2[--n];
        }
    }
};
