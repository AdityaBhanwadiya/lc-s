class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int l = 0, r = 0;
        int n = s.length();
        unordered_map<char, int> index;

        while(r<n) {
            if(index.find(s[r]) != index.end()) {
                if(index[s[r]] >= l){
                    l = index[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxLen = max (len, maxLen);
            index[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};