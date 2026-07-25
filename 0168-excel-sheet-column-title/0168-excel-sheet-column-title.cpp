class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        int num=columnNumber;
        while(num){
            num--;
            int rem=num%26;
            ans=char('A'+rem)+ans;
            num/=26;
        }
        return ans;
    }
};