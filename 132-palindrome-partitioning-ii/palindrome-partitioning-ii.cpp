class Solution {
private:
    bool isPalindrome(int i, int j, string s) {
        while(i < j) {
            if(s[i] != s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    int func (int i, int n, string& s, vector<int>& dp) {
        //base
        if(i == n)  return 0;

        if(dp[i] != -1) return dp[i];

        int minCost = INT_MAX;

        for(int j=i;j<n;j++){
            if(isPalindrome(i, j, s)){
                int cost = 1 + func(j+1, n, s, dp);
                minCost = min (minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[n] = 0;

        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) { // Length of substring
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 1 || len == 2) {
                        isPalindrome[i][j] = true; // Single character or two matching chars
                    } else {
                        isPalindrome[i][j] = isPalindrome[i + 1][j - 1]; // Expand previous palindrome check
                    }
                }
            }
        }

        for(int i=n-1;i>=0;i--) {
            int minCost = INT_MAX;

            for(int j=i;j<n;j++){
                if(isPalindrome[i][j]){
                    int cost = 1 + dp[j+1];
                    minCost = min (minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }
};