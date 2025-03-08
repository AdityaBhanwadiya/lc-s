class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int countB = 0, minFlips = k;

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'B') countB++;
        }
        minFlips = k - countB; 

        for (int i = k; i < n; i++) {
            if (blocks[i] == 'B') countB++;  
            if (blocks[i - k] == 'B') countB--; 

            minFlips = min(minFlips, k - countB);
            if (minFlips == 0) return 0; 
        }

        return minFlips;
        }
};
