// we have to find a minimum ship capacity such that we can ship all package in given order in given days.
// easisest ans would be to sum all weights and send on day 1
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 days = 5
// 45

// left = 1, right = 45
// mid = 23
// when cap = 23, we can send:
// day 1: 1+2+3+4+5+6
// day2: 7+8
// day3: 9+10
// so if cap is 23, we can do in 3 days but our goal is to reduce the cap and we have buffer of 2 more days, hence we reduce the cap so right = mid - 1;
// left = 1, right = 22, mid = 11
// d1: 1+2+3+4
// d2: 5+6
// d3: 7
// d4: 8
// d5: 9
// We out of days so increase the cap so left = mid+1;
// left = 12, right = 22, mid = 17
// And so on....

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int result = 0;

        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int tempSum = 0;
            int daysUsed = 1; // at least 1 day needed

            for (int i = 0; i < n; i++) {
                if (tempSum + weights[i] > mid) {
                    daysUsed++;
                    tempSum = weights[i];
                } else {
                    tempSum += weights[i];
                }
            }

            if (daysUsed <= days) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }

        return result;
    }
};
