class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(auto it : nums){
            freq[it]++;
        }

        int half = ceil((double)n/2);
        for(auto it : freq){
            if(it.second >= half){
                return it.first;
            }
        }
        return 0;
    }
};