class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sign = 1;
        int n = s.length();
        int num = 0;
        int result = 0;

        //  2 + (3 - (4 + 5))

        for(int i=0;i<n;i++) {
            char c = s[i];

            if(isdigit(c)){
                num = num * 10 + (c - '0');
            } else if(c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if(c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }else if(c == ')') {
                result += sign * num;
                num = 0;
                result *= st.top();st.pop();
                result += st.top();st.pop();
            }
        }
        result += sign * num;
        return result;
    }
};