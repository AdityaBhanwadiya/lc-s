class Solution {
private:
    int func (int i, int j, string s, string t, vector<vector<int>>& dp) {
        //base
        if(j == 0)  return i;
        if(i == 0)   return j;
        

        if(dp[i][j] != -1)  return dp[i][j];

        if(s[i-1] == t[j-1])
            return dp[i][j] = 0 + func(i-1, j-1, s, t, dp);
        else{
            return dp[i][j] = 1 + min(min(func(i, j-1, s, t, dp), func(i-1, j, s, t, dp)), func(i-1, j-1, s, t, dp));
        }
    }
public:
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();

        // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int j=1;j<=m;j++){
            prev[j] = j;
        }

        for(int i=1;i<=n;i++) {
            curr[0] = i;
            for(int j=1;j<=m;j++) {
                if(s[i-1] == t[j-1])
                    curr[j] = 0 + prev[j-1];
                else{
                    curr[j] = 1 + min(min(curr[j-1], prev[j]), prev[j-1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};