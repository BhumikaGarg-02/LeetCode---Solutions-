class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                stk.push(s[i]);
            }
            else if(s[i]==')' || s[i]==']' || s[i]=='}'){
                if(stk.size()==0){
                    return false;
                }
                else{
                    char temp=stk.top();
                    stk.pop();
                    if(temp=='('){
                        if(s[i]!=')'){
                            return false;
                        }
                    }
                    else if(temp=='['){
                        if(s[i]!=']'){
                            return false;
                        }
                    }
                    else if(temp=='{'){
                        if(s[i]!='}'){
                            return false;
                        }
                    }
                }
            }
        }
        if(stk.size()!=0){
            return false ;
        }
        return true ;
    }

};