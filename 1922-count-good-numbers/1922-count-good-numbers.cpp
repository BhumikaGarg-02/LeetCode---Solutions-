class Solution {
private:
    const int MOD=1e9+7;

    long long myPow(long long x, long long n) {
        long long ans=1.0;
        long long nn=n;
        if(n<0){
            nn=-1*nn;
            x=(long long)1.0/x;}
        while(nn){
            if(nn%2){
                ans=(ans*x)%MOD;
                nn=nn-1;
            }
            else{
                x=(x*x)%MOD;
                nn=nn/2;
            }
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        long long even_ways=myPow(5,even);
        long long odd_ways=myPow(4,odd);
        return (even_ways*odd_ways)%MOD;
    }
};