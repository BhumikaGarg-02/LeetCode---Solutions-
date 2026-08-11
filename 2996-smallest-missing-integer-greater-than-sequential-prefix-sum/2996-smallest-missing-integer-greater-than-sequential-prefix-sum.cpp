class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int i=1;
        int sum=nums[0];
        int n=nums.size();
        while(i<n){
            if(nums[i]!=nums[i-1]+1){break;}
            sum+=nums[i];
            i++;
        }
        unordered_set<int>s(nums.begin(),nums.end());
        while(s.count(sum)){
            sum++;
        }
        return sum;
    }
};