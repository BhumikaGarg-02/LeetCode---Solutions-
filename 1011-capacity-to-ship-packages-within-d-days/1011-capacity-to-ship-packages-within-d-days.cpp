class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int h=0;
        int n=weights.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            h+=weights[i];
            maxi=max(maxi,weights[i]);
        }
        int l=maxi;
        int ans=h;
        while(l<=h){
            int mid=l+(h-l)/2;
            int cnt=0,sum=0;
            for(int i=0;i<n;i++){
                sum+=weights[i];
                if(weights[i]>mid){
                    l=mid+1;
                    break;
                }
                if(sum>mid){
                    cnt++;
                    sum=0;
                    i--;
                }
            }
            if(sum<=mid){cnt++;}
            if(cnt<=days){
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