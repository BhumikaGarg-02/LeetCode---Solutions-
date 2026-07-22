class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(n<0){
            nn=-1*nn;
            x=(double)1.0/x;}
        while(nn){
            if(nn%2){
                ans=ans*x;
                nn=nn-1;
            }
            else{
                x=x*x;
                nn=nn/2;
            }
        }
        return ans;
    }
};