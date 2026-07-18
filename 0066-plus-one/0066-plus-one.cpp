class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int j=n-1;
        while(j>=0){
            if(digits[j]>=0 && digits[j]<=8){
                digits[j]+=1;
                break;
            }
            if(digits[j]==9){
                digits[j]=0;
                if(j-1<0){
                    vector<int>ans(n+1,0);
                    ans[0]=1;
                    return ans;
                }
                j--;
            }
        }
        return digits;
    }
};