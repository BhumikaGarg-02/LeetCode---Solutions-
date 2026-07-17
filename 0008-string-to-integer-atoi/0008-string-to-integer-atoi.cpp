class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        // for leading space 
        while(i<n && s[i]==' ')i++;
        // for sign
        int sign=1;
        if(i<n &&( s[i]=='-'||s[i]=='+')){
            if(s[i]=='-'){sign=-1;}
            i++;}
        //for leading zeros
        while(i<n && s[i]=='0'){i++;}
        if(i>=n)return 0;
        //for rest of numbers;
        long long num=0;
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                int digit=s[i]-'0';
                num=(num*10)+digit;
                if(sign==-1 && (-1*num)<=-2147483648){return -2147483648;}
                if(sign==1 && num>=2147483647){return 2147483647;}
                i++;
                }
            else break;
        }
        return num*sign;
    }
};