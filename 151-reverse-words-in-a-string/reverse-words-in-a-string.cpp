class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string result="";
        string word;

        stringstream ss(s);
        while (ss >> word) {
            st.push(word);
        }

        while(!st.empty()){
            result += st.top();
            if(st.size() > 1)   result+=" ";
            st.pop();
        }

        return result;
    }
};