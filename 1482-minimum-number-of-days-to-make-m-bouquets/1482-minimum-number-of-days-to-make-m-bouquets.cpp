class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
         if(bloomDay.size()<(long long)m*k){return -1;}
        int maxi=bloomDay[0];
        int mini=bloomDay[0];
        for(int i=1;i<bloomDay.size();i++){
            if(bloomDay[i]>maxi){maxi=bloomDay[i];}
            else if(bloomDay[i]<mini){mini=bloomDay[i];}
        }
        int l=mini,h=maxi;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            int cnt=0;
            int nob=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){cnt++;}
                else{
                    nob += cnt/k;
                    cnt=0;
                }
            }
            nob+=cnt/k;
            if(nob>=m){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};