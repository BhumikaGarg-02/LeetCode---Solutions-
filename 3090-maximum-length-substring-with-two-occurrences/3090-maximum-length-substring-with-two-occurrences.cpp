class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>freq(26,0);
        int n=s.size();
        int maxi=INT_MIN;
        int i=0;
        int start=0;
        while(i<n){
            while(i<n && freq[s[i]-'a']+1 <=2){
                freq[s[i]-'a']++;
                i++;
            }
            maxi=max(maxi,i-start);
            while(i<n && start<i && freq[s[i]-'a']+1>2){
                freq[s[start]-'a']--;
                start++;
            }
        }
        maxi=max(maxi,i-start);
        return maxi;
    }
};