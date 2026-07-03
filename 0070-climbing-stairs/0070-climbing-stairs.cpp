class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n ;
        }
        int sum ;
            int a=1 ;
            int b=2 ;
            for(int i=1 ; i<=n-2;i++){
                sum=a+b;
                a=b;
                b=sum;
            }
        
        return sum;
    }
};