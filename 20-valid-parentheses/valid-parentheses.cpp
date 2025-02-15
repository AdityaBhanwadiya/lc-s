class Solution {
public:
// edge cases: string len 1, pop before push, stack not empty
    bool isValid(string s) {
        if(s.length() == 1) return false;
        stack<char> st;

        for(auto c : s) {
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            }else {
                if(!st.empty()){
                    char temp = st.top();
                    if((temp == '{' && c == '}') || (temp == '[' && c == ']') || (temp == '(' && c == ')')){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
                
            }
        }

        if(st.empty())  return true; 
        return false;
    }
};