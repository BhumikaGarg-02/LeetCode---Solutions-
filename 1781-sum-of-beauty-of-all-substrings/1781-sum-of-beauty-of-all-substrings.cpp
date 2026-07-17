class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int cnt=0;
        for(int j=0;j<=n;j++){
            vector<int>mpp(26,0);
            for(int i=j;i<n;i++){
                mpp[s[i]-'a']++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(int k=0;k<=25;k++){
                    if(mpp[k]>0){
                        maxi=max(maxi,mpp[k]);
                        mini=min(mini,mpp[k]);
                    }
                }
                cnt+=(maxi-mini);
            }
        }
        return cnt;
    }
};