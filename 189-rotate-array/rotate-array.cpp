class Solution {
public:
    // 1 2 3 4 5 6 7 1 2 3 4 5 6 7
    void reverse (vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start++], arr[end--]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        // reverse whole array
        reverse(nums, 0, nums.size() - 1);

        // reverse first k 
        reverse(nums, 0, k-1);

        // reverse rest n-k
        reverse(nums, k, nums.size() - 1);
    }
}; 