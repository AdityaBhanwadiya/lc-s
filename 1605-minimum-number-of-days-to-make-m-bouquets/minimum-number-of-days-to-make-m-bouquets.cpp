class Solution {
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
//                                    lrm
// on day 6, can we make any bouquet? No so we gotta check further left = mid + 1
// on day 9, we can see that days with 7 flowers must have bloomed so find how many group of 3 flowers (adjacent) are bloomed on or before day 9. That is 1 (1, 2, 3), hence one bouquet can be made
// If we are able to make on 9, we can do on other days further. 
// nothing on 11
// on 12, you get more 1 group of 3 so one more boquet



// 1, 2, 3, 4, 5, 6, 7 8, 9, 10
// l           m             r

private:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int bouquetCount = 0;
        int consecutive = 0;

            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] <= day) {
                    consecutive++; // this flower is bloomed and usable
                    if (consecutive == k) {
                        bouquetCount++; // we got one full bouquet
                        consecutive = 0; // reset for next bouquet
                    }
                } else {
                    consecutive = 0; // reset if flower is not bloomed yet
                }
            }
        return bouquetCount>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long random = m * 1LL * k * 1LL;
        if(random > bloomDay.size())   return -1;

        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

        int left = 1, right = maxDay;

    

        while(left<=right) {
            int mid = left + (right - left)/2;
            if(possible(bloomDay, mid, m, k)){
                right = mid -1;
            }
            else
                left = mid+1;
        }
        return left;
    }
};