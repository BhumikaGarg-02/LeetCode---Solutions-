class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int maxi=-1;
        if(k==n){
            for(int i=0;i<n;i++){
                maxi=max(maxi,nums[i]);
            }
            return maxi;
        }
        if(k==1){
            for(int i=0;i<n;i++){
                mpp[nums[i]]++;
            }
            for(auto it:mpp){
                if(it.second==1){
                    maxi=max(maxi,it.first);
                }
            }
            return maxi;
        }
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        if(mpp[nums[0]]!=1 && mpp[nums[n-1]]!=1)return -1;
        else if(mpp[nums[0]]==1 && mpp[nums[n-1]]==1){
            return max(nums[0],nums[n-1]);
        }
        else if(mpp[nums[0]]==1)return nums[0];
        else return nums[n-1];
    }
};