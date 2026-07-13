class Solution {
private:
    bool allocation(vector<int>& nums, int max_splits,int k){
        int split=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max_splits){return false;}
            if(cnt+nums[i]>max_splits){
                split++;
                cnt=nums[i];
            }
            else cnt+=nums[i];
        }
        if(split>k){return false;}
        else return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int h=0;
        int l=INT_MAX;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            h+=nums[i];
            l=min(l,nums[i]);
        }
        while(l<=h){
            int mid=(l+h)/2;
            if(allocation(nums,mid,k)==true){
                ans=mid;
                h=mid-1;
            }
            else{l=mid+1;}
        }
        return ans;
    }
};