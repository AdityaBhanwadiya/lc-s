class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        int cnt = 0;

        for (char c : s) {
            if (c == '(') {
                cnt++;
                res += c;
            } else if (c == ')') {
                if (cnt > 0) {
                    cnt--;
                    res += c;
                }
            } else {
                res += c; 
            }
        }

        string filtered;
        for (int i = res.size() - 1; i >= 0; --i) {
            if (res[i] == '(' && cnt > 0) {
                cnt--;
                continue; 
            }
            filtered += res[i];
        }

        reverse(filtered.begin(), filtered.end());
        return filtered;
    }
};
// lee(t(c)o)de)
// open = 0
