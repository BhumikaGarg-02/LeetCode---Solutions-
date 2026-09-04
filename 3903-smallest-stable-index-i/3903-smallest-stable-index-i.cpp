class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        vector<int>minimum(n,0);
        for(int i=n-1;i>=0;i--){
            mini=min(nums[i],mini);
            minimum[i]=mini;
        }
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            mini=minimum[i];
            int score=maxi-mini;
            if(score<=k){
                  return i;
                }
            
        }
        return -1;
    }
};