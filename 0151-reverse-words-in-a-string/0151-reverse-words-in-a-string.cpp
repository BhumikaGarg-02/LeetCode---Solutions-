class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
     reverse(s.begin(),s.end());
     string ans = "";
     for(int i = 0; i<n; i++){
        string word = "";
        while(i<n && s[i] != ' '){
            word += s[i];
            i++;
        }
        reverse(word.begin(),word.end());
        if(word.length()>0){
            if(!ans.empty()){ans.push_back(' ');}
            ans +=word;
        }

    }
    return ans;
    }
};