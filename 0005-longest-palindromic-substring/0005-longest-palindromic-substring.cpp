class Solution {
private:
    bool palindrome(string &s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){return false;}
            else{start++;
            end--;}
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int cnt=0;
        int start=-1;
        for(int i=0;i<n;i++){
            if(n-i<=cnt)break;
            for(int j=n-1;j>=i;j--){
                if(j-i+1<=cnt){break;}
                else if(palindrome(s,i,j)==true){
                    cnt=j-i+1;
                    start=i;
                    break;
                }
            }
        }  
        return s.substr(start,cnt);
    }
};