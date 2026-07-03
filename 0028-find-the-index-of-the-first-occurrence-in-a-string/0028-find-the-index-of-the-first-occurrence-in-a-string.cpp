class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0 ;
        int j=0 ;
        int n=haystack.size();
        int m=needle.size();
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==m){
                return i-j ;
            }
            else if(haystack[i]!=needle[j] && i<n){
                if(j==0){
                    i++;
                }
                else{
                    i=i-j+1;
                    j=0;
                }
            }
        }
        return -1;
    }
};