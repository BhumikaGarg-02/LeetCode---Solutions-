class Solution {
private:
    int possible(vector<int>& nums,int n,int digit){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=(nums[i]+digit-1)/digit;
        }
        return cnt;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        int l=1,h=maxi;
        while(l<=h){
            int mid=(l+h)/2;
            int sum=possible(nums,n,mid);
            if(sum<=threshold){
                h=mid-1;
            }
            else{l=mid+1;}
        }
        return l;
    }
};