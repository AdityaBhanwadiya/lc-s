class Solution {
private:
    int isPossible (vector<int>& nums, int maxCapacity ) {
        int kCap = 1, currCap = 0;

        for(int i=0;i<nums.size();i++) {
            if(nums[i] + currCap <= maxCapacity) {
                currCap += nums[i];
            }else{
                kCap++;
                currCap = nums[i];
            }
        }
        return kCap;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        if(k == nums.size())    return maxi;

        int left = maxi;

        int right = accumulate(nums.begin(), nums.end(), 0);
        int result = 0;

        // your left in our case would be 8 and right would be 25

        while(left<= right) {
            int mid = left + (right - left)/2; // mid will be 16. 
            int arraysCreated = isPossible (nums, mid);
            if(arraysCreated <= k) {
                result = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return result;
    }
};