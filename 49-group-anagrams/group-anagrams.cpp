class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vec;

        if(strs.size() == 0)    return vec;

        unordered_map<string, vector<string>> myMap;

        for(auto it : strs) {
            string temp = it;
            sort(temp.begin(), temp.end());

            myMap[temp].push_back(it);

            
        }

        for(auto it : myMap) {
            vec.push_back(it.second);
        }
        return vec;
    }
};