class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=1;
        int j=0;
        int n=nums.size();
        while(j<n){
            while(j+1<n && nums[j+1]==nums[j])j++;
            if(nums[j]%k!=0)j++;
            else if(nums[j]/k!=i)return k*i;
            else{i++;
                 j++;}
        }
        return k*i;
    }
};