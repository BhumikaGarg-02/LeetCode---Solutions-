class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int j=0;
        int cnt=0;
        for(int j=0;j<=n-3;j++){
            map<char,int>mpp;
            for(int i=j;i<n;i++){
                mpp[s[i]]++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto it:mpp){
                    maxi=max(maxi,it.second);
                    mini=min(mini,it.second);
                }
                cnt+=(maxi-mini);
            }
        }
        return cnt;
    }
};