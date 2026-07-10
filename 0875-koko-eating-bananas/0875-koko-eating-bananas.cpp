class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=piles[0];
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int l=1,high=maxi ;
        int ans=0;
        while(l<=high){
            int mid=(l+high)/2;
            long long hrs=0;
            for(int i=0;i<piles.size();i++){
                hrs+=ceil((double)piles[i]/(double)mid);
            }
            if(hrs<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};