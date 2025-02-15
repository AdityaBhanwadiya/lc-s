class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // Might have to convert a set to vector later
        vector<vector<int>> ans;
        set<vector<int>> mySet;

        int left = 0, right = 0;

        for(int i=0;i<nums.size();i++){
            left = i+1;
            right = nums.size() - 1;
            while(left < right){
                int currSum = nums[i] + nums[left] + nums[right];
                if(currSum == 0){
                    mySet.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                } else if(currSum < 0){
                    left++;
                } else{
                    right--;
                }
            }
        }

        for(auto it : mySet) {
            ans.push_back(it);
        }
        return ans;
    }
};