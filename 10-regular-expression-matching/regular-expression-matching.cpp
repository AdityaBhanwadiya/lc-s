class Solution {
public:
    bool isMatch(string s, string p) {
        int u = s.size(), v = p.size();
        vector<vector<bool>> patra(u + 1, vector<bool>(v + 1, false));

        patra[0][0] = true;

        // Handle '*' in pattern
        for (int j = 1; j <= v; j++) {
            if (p[j - 1] == '*') {
                patra[0][j] = patra[0][j - 2]; // '*' removes previous char
            }
        }

        for (int i = 1; i <= u; i++) {
            for (int j = 1; j <= v; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    patra[i][j] = patra[i - 1][j - 1]; // Direct match or '.'
                } 
                else if (p[j - 1] == '*') {
                    patra[i][j] = patra[i][j - 2];  // '*' removes previous char
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        patra[i][j] = patra[i][j] || patra[i - 1][j];  // '*' repeats
                    }
                }
            }
        }

        return patra[u][v];
    }
};
