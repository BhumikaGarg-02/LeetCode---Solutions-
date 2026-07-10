class Solution {
private:
    bool possible(vector<int>& bloomDay, int m, int k,int day){
        int cnt=0;
        int nob=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){cnt++;}
            else{
                nob += cnt/k;
                cnt=0;
            }
        }
        nob+=cnt/k;
        if(nob>=m)return true;
        else return false;
    }
    vector<int> mxmn(vector<int>& bloomDay){
        int maxi=bloomDay[0];
        int mini=bloomDay[0];
        for(int i=1;i<bloomDay.size();i++){
            if(bloomDay[i]>maxi){maxi=bloomDay[i];}
            else if(bloomDay[i]<mini){mini=bloomDay[i];}
        }
        return {mini,maxi};
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        vector<int> v=mxmn(bloomDay);
        int l=v[0],h=v[1];
        int ans=-1;
        if(bloomDay.size()<(long long)m*k){return -1;}
        while(l<=h){
            int mid=(l+h)/2;
            if(possible(bloomDay,m,k,mid)==true){
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