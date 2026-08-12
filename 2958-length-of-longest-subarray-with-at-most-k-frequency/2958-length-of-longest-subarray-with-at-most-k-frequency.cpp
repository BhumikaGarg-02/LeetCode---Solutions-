class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int i=0;
        int maxi=0;
        int n=nums.size();
        int start=0;
        while(i<n){
            if((mpp[nums[i]]+1)<=k){
                mpp[nums[i]]++;
                i++;
            }
            else {
                maxi=max(maxi,i-start);
                while(start<=i && mpp[nums[i]]+1>k){
                mpp[nums[start]]--;
                start++;
            }
            }
        }
        maxi=max(maxi,i-start);
        return maxi;
    }
};