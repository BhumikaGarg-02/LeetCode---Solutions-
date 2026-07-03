class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int el=0 ;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            el = el^nums[i];
        }
        return el ;
    }
};