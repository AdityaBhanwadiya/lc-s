class Solution {
private:
    int func (int i, int j, string s, string t, vector<vector<int>>& dp) {
        //base
        if(j < 0)  return i+1;
        if(i < 0)   return j+1;
        

        if(dp[i][j] != -1)  return dp[i][j];

        if(s[i] == t[j])
            return dp[i][j] = 0 + func(i-1, j-1, s, t, dp);
        else{
            return dp[i][j] = 1 + min(min(func(i, j-1, s, t, dp), func(i-1, j, s, t, dp)), func(i-1, j-1, s, t, dp));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return func(n-1, m-1, word1, word2, dp);
    }
};