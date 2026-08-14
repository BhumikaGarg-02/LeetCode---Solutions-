class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>freq(26,0);
        int n=s.size();
        int maxi=INT_MIN;
        int start=0;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            while(freq[s[i]-'a']>2){
                freq[s[start]-'a']--;
                start++;
            }
            maxi=max(maxi,i-start+1);
        }
        return maxi;
    }
};