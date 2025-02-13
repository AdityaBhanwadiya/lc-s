class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;

        for(auto it : nums){
            myMap[it]++;
        }

        multimap<int, int> mm;
        for(auto it : myMap) {
            mm.insert({it.second, it.first});
        } 

        vector<int> res;
        auto it = mm.rbegin();

        while(it != mm.rend() && k > 0){
            res.push_back(it->second);
            k--;
            it++;
        }
        return res;
    }
};