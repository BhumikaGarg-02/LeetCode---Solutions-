class Solution {
public:
    bool isPalindrome(string s) {
        int i=0 ;
        int j= s.length()-1;
        while(i<=j){
            if(i<j && !isalnum(s[i])){
                i++;
            }
            else if(i<j && !isalnum(s[j])){
                j--;
            }
            else if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            else if(tolower(s[i])==tolower(s[j])){
                i++;
                j--;
            }
        }
        return true ;
    }
};