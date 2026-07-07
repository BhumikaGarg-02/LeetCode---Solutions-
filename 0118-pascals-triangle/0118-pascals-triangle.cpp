class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if(numRows==1){
            ans.push_back({1});
            return ans;
        }
        if(numRows==2){
            ans.push_back({1});
            ans.push_back({1,1});
            return ans;
        }
        ans.push_back({1});
        ans.push_back({1,1});
       for(int i=3;i<=numRows;i++){
        vector<int>l;
        int k=i-2;
        for(int j=0;j<ans[k].size();j++){
            if(j==0){
                l.push_back(ans[k][j]);
            }
            else{
                l.push_back(ans[k][j]+ans[k][j-1]);
            }
        }
        l.push_back(1);
        ans.push_back(l);
       }
       return ans;
    }
};