class Solution {
private:
    int func (int i, int prev, vector<int>& nums, vector<vector<int>> dp) {
        //base
        if(i == nums.size())    return 0;

        if(dp[i][prev + 1] != -1)   return dp[i][prev + 1];
        // explore
        int notTake = 0 + func(i+1, prev, nums, dp);

        int take = INT_MIN;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + func (i+1, i, nums, dp);
        }

        // return 
        return dp[i][prev + 1] = max(notTake, take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // vector<int> ahead (n+1, 0);
        // vector<int> curr (n+1, 0);

        // // base
        // // for(int prev = 0;prev<=n;prev++){
        // //     dp[n][prev] = 0;
        // // }

        // for(int i=n-1;i>=0;i--){
        //     for(int j=i-1;j>=-1;j--) {
        //         // explore
        //         int notTake = 0 + ahead[j + 1];

        //         int take = INT_MIN;
        //         if(j == -1 || nums[i] > nums[j]){
        //             take = 1 + ahead[i+1];
        //         }

        //         // return 
        //         curr[j + 1] = max(notTake, take);
        //     }
        //     ahead = curr;
        // }
        // return ahead[-1+1];

        // algorithmic approach
    //     vector<int> dp (n, 1);
    //     int ans = 0;

    //     for(int ind=0;ind<n;ind++) {
    //         for(int prev = 0;prev < ind ;prev++) {
    //             if(nums[prev] < nums[ind]) {
    //                 dp[ind] = max(1+dp[prev], dp[ind]);
    //             }
    //         }
    //         ans = max(ans, dp[ind]);
    //     }
        
    // return ans;


    // Binary Search

    vector<int> temp;
    temp.push_back(nums[0]);

    for(int i=1;i<n;i++){
        if(nums[i] > temp.back()){
            temp.push_back(nums[i]);
        }else{
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
        }
        return temp.size();
    }
};