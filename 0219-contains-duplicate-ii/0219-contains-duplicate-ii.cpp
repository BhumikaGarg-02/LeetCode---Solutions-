class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.empty() || (mpp.find(nums[i])==mpp.end())){
                mpp[nums[i]]=i;
            }
            else{
                int j=mpp[nums[i]];
                if((i-j)<=k)return true;
                else{mpp[nums[i]]=i ;}
            }
        }
        return false;
    }
};