class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string res="";

        for(int i=0;i<num.size();i++) {
            while(!st.empty() && k>0 && st.top()-'0' > num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]); // 0 2 0 0
        }

        // if all increasing which keeps k as it is
        while(k>0){
            st.pop();
            k--;
        }

        while(!st.empty()) {
            res += st.top(); // 0 0 2 0
            st.pop();
        }
        // 0 0 2 0 to 0 2 0 0 -> 200

        while(res.size() != 0 && res.back() == '0')
        {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        
        return res.empty() ? "0" : res;
    }
        
};


// iTs basicaly bringing all smaller numbers utmost left, so we try to remove larger k elems from left.
// 