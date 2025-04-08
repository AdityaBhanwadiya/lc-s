// given an array with missing numbers in between which doesnt make it consec 
// from that missing numbers, you find the kth.
// 2, 3, 4, 7, 11 k=5
// missing: 1, 5, 6, 8, 9, 10 -> return 9
// if k was 8 instead of 5, we would have to add the numbers at end
// 1, 5, 6, 8, 9, 10, 12, 13 -> return 13

// 1, 2, 3, 4 k = 2
// 5, 6 return 6

// to find if our ans would be there in between the given range (like max of current given array)
// 1 to 11 -> 11 numbers, out of that 11, we have 5 so there are 5 numbers missing and we want 5th from it so yes we good.

// 1 to 4-> 4 total, out of that 4, we have 4 so none, we gotta go beyond what we have till k.

// For btwn, we expect at every index the number to be i+1, if its not we move our mid acc
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
            int left = 0, right = n-1;
            while(left<=right) {
                int mid = left + (right - left)/2;
                int missingNumbersCount = arr[mid] - mid - 1;

                if(missingNumbersCount < k){
                    left = mid + 1;
                }else{
                   right = mid - 1; 
                }

            }
        return k + right + 1;
    }
};
