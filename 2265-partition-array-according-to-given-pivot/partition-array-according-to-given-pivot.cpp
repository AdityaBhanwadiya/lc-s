class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n); 
        int left = 0, count = 0;

        for (int num : nums) {
            if (num < pivot)    result[left++] = num;
            else if (num == pivot)  count++;
        }

        int mid = left;
        while (count-- > 0) result[left++] = pivot;

        for (int num : nums) {
            if (num > pivot)    result[left++] = num;
        }

        return result;
    }
};
