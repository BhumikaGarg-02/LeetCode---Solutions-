class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xor1=0;
       bool allzero=true;
       for(int x:nums){
        xor1^=x;
        if(x>0){
            allzero=false;
        }
       }
       if(xor1!=0)return n;
       return allzero?0:n-1;
    }
};