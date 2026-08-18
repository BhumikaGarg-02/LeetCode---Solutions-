class Solution {
private:
    void parent(string current,int n,int open,int close,vector<string>&result){
        if(current.size()==2*n){
            result.push_back(current);
            return;
        }
        if(open<n){
            parent(current+'(',n,open+1,close,result);
        }
        if(close<open){
            parent(current+')',n,open,close+1,result);
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        int open=0;
        int close=0;
        parent("",n,open,close,result);
        return result;
    }
};