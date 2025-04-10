class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> myMap;
        vector<int> used(256, 0);  

        for(int i = 0; i < s.length(); i++) {
            if(myMap.find(s[i]) == myMap.end()) {
                if (used[t[i]]) return false; 
                myMap[s[i]] = t[i];
                used[t[i]] = 1;
            } else {
                if (myMap[s[i]] != t[i]) return false; 
            }
        }

        return true;
    }
};
