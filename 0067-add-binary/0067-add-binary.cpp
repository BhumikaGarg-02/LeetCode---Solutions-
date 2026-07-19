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
            if(i>=0){
               carry+=a[i]-'0';
                i--;
                }
            if(j>=0){
               carry+=b[j]-'0';
                j--;
                }
            ans+=(carry%2)+'0';
            carry=carry/2;
        }
        if(carry==1){ans.push_back(1+'0');}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};