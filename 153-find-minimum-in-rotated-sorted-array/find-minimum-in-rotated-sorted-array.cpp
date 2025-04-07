class Solution {
public:
    
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n-1;

        int mini = INT_MAX;
        while(left<= right) {
            int mid = left + (right - left)/2;

            if(arr[left] <= arr[mid]) {
                mini = min(mini, arr[left]);
                left = mid + 1;
            }else {
                mini = min(mini, arr[mid]);
                right = mid - 1;
            }
        }
        return mini; 
    }
};