class Solution {
private: 
    void subset(vector<int>&nums,int n,int i,vector<int>&current,vector<vector<int>>&result){
        if(i>=n){
            result.push_back(current);
            return;
        }
        current.push_back(nums[i]);
        subset(nums,n,i+1,current,result);
        int el=current.back();
        current.pop_back();
        i++;
        while(i!=n && nums[i]==el)i++;
        subset(nums,n,i,current,result);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>current;
        vector<vector<int>>result;
        subset(nums,n,0,current,result);
        return result;
    }
};