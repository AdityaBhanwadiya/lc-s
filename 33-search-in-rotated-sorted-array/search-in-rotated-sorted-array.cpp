class Solution {
public:
    // 7 8 9 1 2 3 4 5 6 - target = 1
    //     l r
    int search(vector<int>& arr, int target) {
        int n = arr.size();

        int left = 0, right = n-1;

        while(left <= right) {
            int mid = (left + right) / 2;

            if(arr[mid] == target)  return mid;
            // left half sorted
            else if(arr[left] <= arr[mid]){
                if(arr[left] <= target && target <= arr[mid]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            // right half sorted
            else{
                if(arr[mid] <= target && target <= arr[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }

        }
        return -1;
    }
};