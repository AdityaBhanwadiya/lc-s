class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        // vector<vector<double>> dp(n+1, vector<double>(m+1, 0));

        vector<double> prev(m+1, 0), curr(m+1, 0);

        //base
        // for(int i=0;i<=n;i++){
        //     dp[i][0] = 1;
        // }

        prev[0] = curr[0] = 1;

        // for(int j=1;j<=m;j++){
        //     dp[0][j] = 0;
        // }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) {
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }else{
                    curr[j] =  prev[j];
                }
            }
            prev = curr;
        }
        

        return (int) curr[m];
    }
};