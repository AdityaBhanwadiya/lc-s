class Solution {
private:
    bool possible (vector<int>& nums, int threshold, int divisor) {
        int newSum = 0;
        for(int i=0;i<nums.size();i++) {
            newSum += (nums[i] + divisor - 1) / divisor;
        }

        return newSum<=threshold;
    }
public:
    // 1, 2, 5, 9
    // sum = 17
    // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17
    // l           m           r
    // 
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = -1;

        while(left<= right) {
            int divisor = left + (right - left) /2;

            if(possible(nums, threshold, divisor)){
                result = divisor;
                right = divisor - 1;
            }else{
                left = divisor + 1;
            }
        }
        return result;
    }
};