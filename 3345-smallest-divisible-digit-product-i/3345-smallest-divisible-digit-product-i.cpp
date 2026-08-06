class Solution {
public:
    int smallestNumber(int n, int t) {
        if(t==1)return n;
        for(int i=1;i<=10;i++){
            int p=1;
            int temp=n;
            while(temp){
                int dig=temp%10;
                p*=dig;
                if(p==0)return n;
                temp=temp/10;
            }
            if(p%t==0)return n;
            else n+=1;
        }
        return 0;
    }
};