class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;

        for(int i=0;i<s.length();i++) {
            unordered_map<char, int> freq;
            for(int j=i;j<s.length();j++) {
                if(freq.find(s[j]) == freq.end()){
                    freq[s[j]]++;
                    int len = j-i+1;
                    maxLen = max(maxLen, len);
                }else{
                    break;
                }
            }
        }
        return maxLen;
    }
};