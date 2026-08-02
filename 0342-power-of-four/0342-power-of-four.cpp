class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        if((n&(n-1))!=0)return false;
        int bit=-1;
        while(n){
            if((n&1)==0)bit++;
            else break;
            n=n>>1;
        }
        if((bit+1)%2==1)return false;
        return true;
    }
};