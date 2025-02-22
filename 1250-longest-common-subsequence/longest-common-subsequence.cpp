class Solution {
private:
    int func (int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        //base
        if(i < 0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1)  return dp[i][j];

        if(s[i] == t[j]){
            return 1 + func(i-1, j-1, s, t, dp);
        }

        return dp[i][j] = max(func (i-1, j, s, t, dp), func (i, j-1, s, t, dp));
    } 
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func (n-1, m-1, s, t, dp);
    }
};