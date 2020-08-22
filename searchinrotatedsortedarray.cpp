/*

Given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You should search for target in nums and if you found return its index, otherwise return -1.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guranteed to be rotated at some pivot.
-10^4 <= target <= 10^4

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot;
        int n=nums.size();
        if(n==0) return -1;
        if(n==1){
            if(nums[0]==target) return 0;
            else return -1;
        }
        
        int l=0,r=n-1,mid;
        while(l<r){
            mid = (l+r)/2;
            if(mid==0 || mid==n-1)
                break;
            if(nums[mid+1]<nums[mid])
                break;
            if(nums[mid]>nums[0])
                l=mid+1;
            else
                r=mid;
        }
        pivot = mid;
        if(nums[0]<nums[n-1]) pivot=n-1;
        if(nums[1]<nums[0]) pivot=0;
        
        l=0,r=pivot;
        bool flag=0;
        mid = bsearch(nums, l, r, target, flag);
        
        if(nums[mid]==target) flag=1;
        if(flag) return mid;
        
        l=pivot+1,r=n-1;
        mid = bsearch(nums, l, r, target, flag);
        
        if(nums[mid]==target) flag=1;
        if(flag) return mid;
        else return -1;
    }
    int bsearch(vector<int>&nums, int l, int r, int target, bool &flag){
        int mid;
        while(l<r){
            mid = (l+r)/2;
            if(nums[mid]==target){
                flag=1;
                break;
            }
            if(nums[mid]<target)
                l=mid+1;
            else
                r=mid;
        }
        mid=(l+r)/2;
        return mid;
    }
};
