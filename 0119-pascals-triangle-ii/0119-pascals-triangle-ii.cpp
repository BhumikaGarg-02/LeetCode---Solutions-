class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n=rowIndex;
        if(n==0){return  {1};}
        if(n==1){return  {1,1};}
        vector<int>ans;
        ans.push_back(1);
        long long res=1;
        for(int i=1;i<=n;i++){
            res=res*(n-i+1);
            res=res/i;
            ans.push_back(res);
        }
        return ans;
    }
};