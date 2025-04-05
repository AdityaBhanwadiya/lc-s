class Solution {
private:
    bool canDivide(const vector<int>& nums, int divisor, int threshold) {
        int total = 0;
        for (int num : nums) {
            total += (num + divisor - 1) / divisor; 
        }
        return total <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, mid, threshold)) {
                answer = mid;   
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }
        return answer;
    }
};