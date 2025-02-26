class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash (n);
        int maxIndex = 0, maxValue = 1;
        sort(nums.begin(), nums.end());


        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > maxValue){
                maxValue = dp[i];
                maxIndex = i;
            }
        }


        vector<int> answer;
        answer.push_back(nums[maxIndex]);

        while(hash[maxIndex] != maxIndex) {
            maxIndex = hash[maxIndex];
            answer.push_back(nums[maxIndex]);
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};