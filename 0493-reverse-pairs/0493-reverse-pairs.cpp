class Solution {
private:
    void merge(vector<int>& nums,int low,int mid,int high){
        vector<int>temp;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    int count(vector<int>& nums,int low,int mid,int high){
        int cnt=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i]>(long long)2*nums[right]){right++;}
            cnt+=(right-(mid+1));
        }
        return cnt;
    }
    int ms(vector<int>& nums,int low,int high){
        int cnt=0;
        if(low>=high){
            return cnt ;
        }
        int mid=(low+high)/2;
        cnt+=ms(nums,mid+1,high);
        cnt+=ms(nums,low,mid);
        cnt+=count(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return ms(nums,0,nums.size()-1);
    }
};