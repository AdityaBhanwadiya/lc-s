class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();

        if(n == 1)  return arr[0];
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mid % 2 == 0) {
                if (arr[mid] == arr[mid + 1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (arr[mid] == arr[mid - 1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return arr[left];
    }
};
