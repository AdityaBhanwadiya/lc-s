class Solution {
private:
    int func (int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        //base
        // if(i < 0 || j < 0){
        //     return 0;
        // }

        for(int i=0;i<=s.length();i++){
            dp[i][0] = 0;
        }

        for(int i=0;i<=t.length();i++){
            dp[0][i] = 0;
        }

        // if(dp[i][j] != -1)  return dp[i][j];

        for(int i=1;i<=s.length();i++) {
            for(int j=1;j<=t.length();j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s.length()][t.length()];
    } 
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        return func (n, m, s, t, dp);
    }
};