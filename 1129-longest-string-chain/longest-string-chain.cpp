class Solution {
private:
    bool func (string s, string t) {
        if (s.length() != t.length() + 1) return false;

        int i = 0, j = 0;
        while(i < s.length()){
            if(s[i] == t[j]){
                i++;j++;
            }else{
                i++;
            }
        }
        if(i == s.length() && j == t.length())  return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // sort based on len, if same do it using chars in increasing order.
        sort(words.begin(), words.end(), [](const string &s1, const string &s2) {
            return s1.length() < s2.length(); // Sort by length
        });

        vector<int> dp(n, 1);
        int maxi = 1;
        
        for(int ind = 0;ind<n;ind++) {
            for(int prev = 0; prev <ind;prev++) {
                if(func(words[ind], words[prev]) && 1 + dp[prev] > dp[ind]){
                    dp[ind] = 1 + dp[prev];
                }
            }
            if(dp[ind] > maxi)
                maxi = max(maxi, dp[ind]);
        }
        return maxi;
    }
};