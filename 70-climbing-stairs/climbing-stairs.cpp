class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1; 

        // vector<int> dp(n+1, 0); 
        int prev1 = 1; // dp[i+1]
        int prev2 = 1; // dp[i+2]

        for (int i = n-2; i >= 0; i--) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1; 
    }
};
