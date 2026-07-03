class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans= "" ;
        int maxlength=strs[0].size();
        int n=strs.size();
        for(int i=0 ; i<n ; i++){
            int l=strs[i].size();
            if(l<maxlength){
                maxlength=l;
            }
        }
        
        for(int i=0;i<maxlength;i++){
            char current=strs[0][i];
            for(int k=1 ; k<n;k++){
                if(strs[k][i]!=current){
                    return ans ;
                }
            }
            ans.push_back(current);
        }
        return ans ;
    }
};