class Solution {
private:
    void ans(vector<int>& current,vector<int>& candidates,int i,int n,int s,int target,vector<vector<int>>&result){
        if(s==target){
            result.push_back(current);
            return;
         }
         if(i>=n || s>target)return;
         current.push_back(candidates[i]);
         s+=candidates[i];
         ans(current,candidates,i,n,s,target,result);
         current.pop_back();
         s-=candidates[i];
         ans(current,candidates,i+1,n,s,target,result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        int n=candidates.size();
        vector<int>current;
        ans(current,candidates,0,n,0,target,result);
        return result;
    }
};