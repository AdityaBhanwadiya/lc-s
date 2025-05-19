class Solution {
public:
    // Look for substrings with at most k zeros.
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int l = 0, r = 0, zeros = 0;
        int len = 0;

        while(r < n) {
            if(nums[r] == 0)    zeros++;

            while(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }
            len = r - l + 1;
            maxLen = max (maxLen, len);
            r++;
        }
        return maxLen;
    }
};