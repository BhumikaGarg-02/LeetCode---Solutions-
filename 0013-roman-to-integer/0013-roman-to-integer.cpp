class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int sum=0 ;
        for(int i=0 ; i<=n-1;i++){
            if(s[i]=='I'){
                if(i+1<n && s[i+1]=='V'){
                    sum=sum+4;
                    i=i+1;
                }
                else if(i+1<n && s[i+1]=='X' ){
                    sum=sum+9;
                    i=i+1;
                }
                else{
                    sum=sum+1;
                }
            }
            else if(s[i]=='X'){
                if(i+1<n && s[i+1]=='L'){
                    sum=sum+40;
                     i=i+1;
                }
                else if(i+1<n && s[i+1]=='C'){
                    sum=sum+90;
                    i=i+1;
                }
                else{
                    sum=sum+10;
                }
            }
            else if(s[i]=='C'){
                if(i+1<n && s[i+1]=='D'){
                    sum=sum+400;
                    i=i+1;
                }
                else if(i+1<n && s[i+1]=='M'){
                    sum=sum+900;
                     i=i+1;
                }
                else{
                    sum=sum+100;
                }
            }
            else if(s[i]=='V'){
                sum=sum+5;
            }
            else if(s[i]=='L'){
                sum=sum+50;
            }
            else if(s[i]=='D'){
                sum=sum+500;
            }
            else if(s[i]=='M'){
                sum=sum+1000;
            }
        }
        return sum ;
    }
};