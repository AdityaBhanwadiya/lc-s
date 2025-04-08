class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) {
                // descending slope
                right = mid;
            } else {
                // ascending slope
                left = mid + 1;
            }
        }
        return left;
    }
};
