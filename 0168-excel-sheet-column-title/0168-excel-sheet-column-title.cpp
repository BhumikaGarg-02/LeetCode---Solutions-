class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        int num=columnNumber;
        while(num){
            num--;
            int rem=num%26;
            ans.push_back('A'+rem);
            num/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};