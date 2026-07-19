class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();
        int i=n-1;
        int j=m-1;
        string ans="";
        int carry=0;
        while(i>=0 || j>=0){
            int sum=carry;
            if(i>=0){
                sum+=a[i]-'0';
                i--;
                }
            if(j>=0){
                sum+=b[j]-'0';
                j--;
                }
            carry=sum/2;
            sum=sum%2;
            ans.insert(0,1,sum+'0');
        }
        if(carry==1){ans.insert(0,1,1+'0');}
        return ans;
    }
};