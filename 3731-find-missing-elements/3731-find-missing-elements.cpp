class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ls;
        int n=nums.size();
        int i=0;
        int j=0;
        sort(nums.begin(),nums.end());
        while(i<n-1){
            if(nums[i]+1!=nums[i+1]){
                ls.push_back(nums[i]+1);
                while((ls[j]+1)!=nums[i+1]){
                    ls.push_back(ls[j]+1);
                    j++;
                }
                j++;
            }
            i++;
        }
        return ls;
    }
};