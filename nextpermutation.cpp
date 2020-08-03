/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int pos=n;
        for(int i=n-1; i>=1; i--){
            if(nums[i]>nums[i-1]){
                pos=i-1;
                break;
            }
        }
        if(pos==n){
            sort(nums.begin(), nums.end());
            return;
        }
        int justgreater=pos+1;
        for(int i=pos+1; i<n; i++){
            if(nums[i]>nums[pos] && nums[i]<=nums[justgreater]) justgreater=i;
        }
        swap(nums[justgreater],nums[pos]);
        for(int i=pos+1; i<=(n-pos)/2+pos; i++){
            swap(nums[i], nums[n-i+pos]);
        }
    }
};
