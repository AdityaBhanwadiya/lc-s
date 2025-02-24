class Solution {
private:
    bool isAllStars(string &p, int j) {
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*')
                return false;
        }
        return true;
    }   

    bool func(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // Base Cases
        if (i < 0 && j < 0) return true;  
        if (j < 0 && i>=0) return false;         
        if (i < 0 && j>=0) return isAllStars(p, j);  

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') 
            return dp[i][j] = func(i-1, j-1, s, p, dp);
        else if (p[j] == '*') 
            return dp[i][j] = func(i-1, j, s, p, dp) || func(i, j-1, s, p, dp);

        return dp[i][j] = false;  // If nothing matches
    }

public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(n - 1, m - 1, s, p, dp);
    }
};
