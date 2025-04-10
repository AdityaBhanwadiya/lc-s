class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int balance=0;

        for(int i=0;i<s.length();i++) {
            if(s[i] == '(') {
                balance++;

                if(balance > 1) result+=s[i];
            }
            else if(s[i] == ')') {
                balance--;

                if(balance > 0) result+=s[i];
            }

            
        }
        return result;
    }
};
