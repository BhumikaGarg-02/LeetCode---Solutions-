class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int cnt=0;
        int i=0;
        int mini=INT_MAX;
        int n=s.size();
        string ans="";
        int start=0;
        int end=0;
        for(int j=0;j<n;j++){
            if(s[j]=='1' && cnt<k){
                cnt++;
                if(cnt==k){
                    while (s[i] == '0') {
                    i++;
                     }
                    int diff=j-i+1;
                    int s1=i;
                    if(diff==mini){
                        for(int m=start ;m<=end;m++){
                            if(s[s1]<s[m]){
                                start=i;
                                end=j;
                                break;
                            }
                            else if(s[s1]>s[m]) {
                                break;
                            }
                            s1++;
                        }
                    }
                    else if(diff<mini){
                        mini=diff;
                        start=i;
                        end=j;
                    }
                    while(i<=j && cnt==k){
                        if(s[i]=='1')cnt--;
                        i++;
                    }
                }
            }  
        }
        if(mini==INT_MAX)return "";
        for(int i=start;i<=end;i++){
            ans.push_back(s[i]);
        }
        return ans;
    }
};