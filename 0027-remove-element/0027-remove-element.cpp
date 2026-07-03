class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int j=n-1;
        for(int i=0;i<n;i++){
            if(nums[i]==val){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                j--;
                i--;
                n=n-1;
            }
        }
        return n ;
    }
};