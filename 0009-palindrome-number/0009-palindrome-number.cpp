class Solution {
public:
    bool isPalindrome(int x) {
        int reverse=0 ;
        int ld ;
        int n = x ;
        if(x>=0){
        while(n!=0){
            ld=n%10 ;
            if(reverse<INT_MIN/10 || reverse>INT_MAX/10){
                return 0 ;
            }
            reverse=(reverse*10)+ld ;
            n=n/10 ;
            }
        if(x==reverse){
            return true ;
        } 
        else{
            return false ;
        }
        }
        else{
            return false ;
        }
    }
};