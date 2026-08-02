class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        int n=start;
        int m=goal;
        while(n){
            if((n&1)==(m&1)){
                n=n>>1;
                m=m>>1;
            }
            else{
                cnt++;
                m=m>>1;
                n=n>>1;
            }
        }
        while(m){
            if((m&1)!=0)cnt++;
            m=m>>1;
        }
        return cnt;
    }
};