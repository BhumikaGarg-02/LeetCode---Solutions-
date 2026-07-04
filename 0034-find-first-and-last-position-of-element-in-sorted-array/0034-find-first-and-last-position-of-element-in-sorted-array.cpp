class Solution {
private:
    int lb(vector<int>&nums,int target){
        int low=0 ;
        int high=nums.size()-1;
        int ans=nums.size();
        while(low<=high){
            long long mid=low+(high-low)/2;
            if (nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans ;
    }
    int ub(vector<int>&nums,int target){
        int low=0 ;
        int high=nums.size()-1;
        int ans=nums.size();
        while(low<=high){
            long long mid=low+(high-low)/2;
            if (nums[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans ;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = lb(nums,target) ;
        int upper = ub(nums,target) ;
        if(lower==nums.size() || nums[lower]!=target){
            return{-1,-1};
        }
        return{lower,upper-1} ;
    }
};