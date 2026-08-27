class Solution {
private:
    void ans(vector<int>&current,vector<vector<int>>&result,int i,int cnt,int sum,int k,int n){
        if(cnt==k && sum==n){
            result.push_back(current);
            return;
        }
        if(i>9 || sum>n || cnt>k)return;
        current.push_back(i);
        ans(current,result,i+1,cnt+1,sum+i,k,n);
        current.pop_back();
        ans(current,result,i+1,cnt,sum,k,n);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>current;
        vector<vector<int>>result;
        ans(current,result,1,0,0,k,n);
        return result;
    }
};