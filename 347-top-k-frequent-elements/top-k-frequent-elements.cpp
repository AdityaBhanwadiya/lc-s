class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto it: nums)
            freq[it]++;
        
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, f] : freq) {
            buckets[f].push_back(num);
        }

        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};