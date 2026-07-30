class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int i=1;
        int ans=0;
        if(n<8)return n;
        else {
            while(n>=8){
                ans+=(8*i);
                i++;
                n=n-8;
            }
            if(n){ans+=(n*i);}
        }return ans;
    }
};