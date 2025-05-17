class Solution {
private:
    int lowerBound (vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int result = -1;

        while(left <= right) {
            int mid = left + (right - left)/2;
            if(nums[mid] >= target) {
                result = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
    int upperBound (vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int result = -1;

        while(left <= right) {
            int mid = left + (right - left)/2;
            if(nums[mid] > target) {
                result = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lowerBound(nums, target);
        int end = upperBound(nums, target);
        if (start >= nums.size() || nums[start] != target)
            return {-1, -1};
        return {start, end-1};
    }
};
