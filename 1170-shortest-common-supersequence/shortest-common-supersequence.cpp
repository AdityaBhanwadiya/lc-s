class Solution {
private:
    void func (int i, int j, string& s, string& t, vector<vector<int>>& dp) {
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
        // return dp[s.length()][t.length()];
    }
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        func (n, m, s1, s2, dp);

        int len = dp[n][m];
        int i = n;
        int j = m;

        string ans = "";

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans += s1[i-1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += s1[i-1];
                i--;
            } else {
                ans += s2[j-1];
                j--;
            }
        }
        
        //Adding Remaing Characters - Only one of the below two while loops will run 
        
        while(i>0){
            ans += s1[i-1];
            i--;
        }
        while(j>0){
            ans += s2[j-1];
            j--;
        }

        reverse(ans.begin(),ans.end());
        
        return ans;

    }
};