class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        string ans="";
        for(int i=0;i<s.size();i++){mpp[s[i]]++ ;}
        vector<string>temp(s.size()+1,"");
        for(auto it:mpp){
            temp[it.second].append(it.second,it.first);
        }
        for(int i=s.size();i>=0;i--){
            if(!temp[i].empty()){
                ans+=temp[i];
            }
        }
        return ans;
    }
};