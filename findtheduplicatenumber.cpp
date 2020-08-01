/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at 
least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
Note:

-You must not modify the array (assume the array is read only).
-You must use only constant, O(1) extra space.
-Your runtime complexity should be less than O(n2).
-There is only one duplicate number in the array, but it could be repeated more than once.
*/


//Floyd's Tortoise and hare algorithm

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise,hare;
        tortoise=nums[0];
        hare=nums[0];
        while(true){
            tortoise=nums[tortoise];
            hare=nums[nums[hare]];
            if(tortoise==hare) break;
        }
        tortoise=nums[0];
        while(tortoise!=hare){
            tortoise=nums[tortoise];
            hare=nums[hare];
        }
        return tortoise;
    }
};
