class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor==dividend)return 1;
        bool sign=true;
        if(dividend>=0 && divisor<0)sign=false;
        if(dividend<0 && divisor>=0)sign=false;
        long n=labs(dividend);
        long d=labs(divisor);
        long ans=0;
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))){cnt++;}
            ans+=(1L<<cnt);
            n-=d<<cnt;
        }
        if(ans>INT_MAX && sign){return INT_MAX;}
        if(ans>INT_MAX && !sign)return INT_MIN;
        return sign?ans :-ans;
    }
};