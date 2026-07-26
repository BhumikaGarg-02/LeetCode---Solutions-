class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum=0;
        for(int i=0;i<columnTitle.size();i++){
            sum=(sum*26)+(columnTitle[i]-'A'+1) ;
        }
        return sum;
    }
};