class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;
        unordered_map<char, int> freq;
        for(auto c : s){
            freq[c]++;
        }

        for(auto c : t) {
            if(freq.find(c) != freq.end()) {
                freq[c]--;
            }
        }

        for(auto it : freq){
            if(it.second > 0){
                return false;
            }
        }
        return true;
    }
};