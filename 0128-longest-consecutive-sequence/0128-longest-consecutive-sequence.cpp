class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0 ;
        }
        sort(nums.begin(),nums.end());
        int cnt=0;
        int longest=1;
        int lastsmaller=INT_MIN;
        for(int i=0 ; i<nums.size();i++){
            if(nums[i]-1==lastsmaller){
                cnt++;
                lastsmaller=nums[i];
            }
            else if(nums[i]!=lastsmaller){
                lastsmaller=nums[i];
                cnt=1;
            }
            longest=max(cnt,longest) ;
        }
        return longest ;
    }
};