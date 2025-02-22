class Solution {
private:
    int func (int i, int j, string& s, string& t, vector<int>& prev, vector<int>& curr) {
        //base
        // if(i < 0 || j < 0){
        //     return 0;
        // }

        // for(int i=0;i<=s.length();i++){
        //     dp[i][0] = 0;
        // }

        for(int i=0;i<=t.length();i++){
            prev[i] = 0;
        }

        // if(dp[i][j] != -1)  return dp[i][j];

        for(int i=1;i<=s.length();i++) {
            for(int j=1;j<=t.length();j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev= curr;
        }
        return prev[t.length()];
    } 
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int>prev(m+1, 0), curr(m+1, 0);
        return func (n, m, s, t, prev, curr);
    }
};