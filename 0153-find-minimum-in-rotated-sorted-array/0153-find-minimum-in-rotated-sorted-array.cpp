class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0 ;
        int h=nums.size()-1;
        int mini=INT_MAX;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(nums[mid]<mini){
                mini=nums[mid];
            }
            if(nums[l]<=nums[mid]){
                if(nums[l]<mini){
                    mini=nums[l];
                }
                l=mid+1;
            }
            else{
                if(nums[mid]<nums[h]){
                    h=mid-1; 
                }
            }
        }
        return mini ;
    }
};