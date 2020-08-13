/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int ans=0,lmax=0,rmax=0;
        
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]>=lmax) lmax=height[l];
                else ans+=(lmax-height[l]);
                l++;
            }
            else{
                if(height[r]>=rmax) rmax=height[r];
                else ans+=(rmax-height[r]);
                r--;
            }
        }
        return ans;
    }
};
