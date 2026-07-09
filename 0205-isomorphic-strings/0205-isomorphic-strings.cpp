class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>st;
        unordered_map<char,char>ts;
        int n=s.length();
        for(int i=0;i<n;i++){
             if(st.find(s[i])!=st.end()){
                if(st[s[i]]!=t[i]){
                    return false;
                }
             }
             else{
                st[s[i]]=t[i];
                }
             if(ts.find(t[i])!=ts.end()){
                if(ts[t[i]]!=s[i]){return false;}
             }
             else{
                ts[t[i]]=s[i];
             }
        }
        return true;
    }
};