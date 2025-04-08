class Solution {
public:
// per hour speed of k 
// random pile every hour and eats k bananas
// one pile at a time
// find minimum k such that all bananas can be done in h hours

// max bananas in a pile is 11 hence if koko eats 11 of them in an hour it'll take 4 hours so def k lies between 1 to 11
// k = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
//.             lm r  
// Try using k as 6

// if k = 6, it'll take 6 hours, so we still got buffer of 2 hours, lets try reducing k
// if k = 3, it exceed our cap of 8, hence increase the k
// if k = 4, it takes exact of 8 hours hence k = 4 is our answer.

// Tc: finding k will take logn time bs but, going through all the piles will take the size of that which is n. According to me it'll take n logn.

// 3 6 7 11 h = 8


    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        int result = 0;

        int left = 1, right = maxPile;

        while(left<=right) {
            int k = left + (right - left)/2;

        long long count = 0;

        for(auto i : piles){
            count += (i + k - 1) / k;
        }

        if(count <= h){
            result = k;
            right = k-1;
        }else{
            left = k+1;
        }
    }
    return result;
}
};