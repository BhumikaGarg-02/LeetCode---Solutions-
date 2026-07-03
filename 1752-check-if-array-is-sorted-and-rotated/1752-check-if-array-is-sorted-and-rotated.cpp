class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int flag = 0 ;
        while(i<n-1){
            if(nums[i]<=nums[i+1]){
                i++;
            }
            else{
                flag = 1;
                reverse(nums.begin(),nums.begin()+i+1);
                reverse(nums.begin()+i+1,nums.end());
                reverse(nums.begin(),nums.end());
                break ;
            }
        }
        if (flag==1){
        for(int i=0 ; i<n-1 ; i++){
            if(nums[i]>nums[i+1]){
                return false ;
            }
        }
        return true ;
        }
        else{
        return true ; }
    }
};