class Solution {
private:
    bool isAllStars(string &p, int j) {
        for (int k = 1; k <= j; k++) {
            if (p[k-1] != '*')
                return false;
        }
        return true;
    }   

    bool func(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // Base Cases
        if (i == 0 && j == 0) return true;  
        if (j == 0 && i> 0) return false;         
        if (i == 0 && j > 0) return isAllStars(p, j);  

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i-1] == p[j-1] || p[j-1] == '?') 
            return dp[i][j] = func(i-1, j-1, s, p, dp);
        else if (p[j-1] == '*') 
            return dp[i][j] = func(i-1, j, s, p, dp) || func(i, j-1, s, p, dp);

        return dp[i][j] = false;  // If nothing matches
    }

public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, false));

        dp[0][0] = true;

        for (int i = 1; i <= n; i++) 
            dp[i][0] = false;


        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-1]; 
            else
                dp[0][j] = false;
        }

        for(int i=1;i<=s.length();i++) {
            for(int j=1;j<=p.length();j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '?') 
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*') 
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }

        return dp[n][m];
    }
};
