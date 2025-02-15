class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)    return 0;
        // just need a single variable to store the len of maximum consec seq;
        int maxi = 0;

        // for faster finds
        unordered_set<int> mySet(nums.begin(), nums.end());

        // 4 5 6 7
        // 7 8 9
        // -1, 0, 1

        
        for(auto it : mySet) {
            if(mySet.find(it - 1) == mySet.end()) {
                int currentNum = it;
                int seqLen = 1;

                // Count consecutive numbers in forward direction
                while(mySet.find(currentNum + 1) != mySet.end()) {
                    currentNum++;
                    seqLen++;
                }

                maxi = max(maxi, seqLen);
            }
        }
        return maxi;
    }
};