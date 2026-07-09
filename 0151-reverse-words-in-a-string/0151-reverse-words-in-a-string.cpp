class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=s.length()-1;
        while(i>=0 ){
            while(i>=0 && s[i]==' '){i--;}
            if(i<0){break;}
            int j=i ;
            while(j>=0 && s[j]!=' '){j--;}
            if(!ans.empty()){ans.push_back(' ');}
            ans.append(s.substr(j+1,i-j));
            i=j;
        }
        return ans;
    }
};