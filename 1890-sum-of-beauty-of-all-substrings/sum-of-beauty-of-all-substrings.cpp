class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int result = 0;
        
        for(int i=0;i<n;i++){
            vector<int> freq(26, 0);

            for(int j = i;j<n;j++){
                freq[s[j] - 'a']++;

                int len = j - i + 1;
                if(len >= 3){
                    int maxi = 0, mini = INT_MAX;
                    for (int k = 0; k < 26; k++) {
                        if (freq[k] > 0) {
                            maxi = max(maxi, freq[k]);
                            mini = min(mini, freq[k]);
                        }
                    }
                    result += (maxi - mini);
                }
            }
        }
        return result;
        
    }
};

// aab, aabc, aabcb, abc, abcb, bcb
// aabcb
// a, a, b, c, b, aa, ab, bc, cb, aab, abc, bcb, aabc, abcb, aabcb
// 0, 0, 0, 0, 0, 0, 0,    0.  0.  1.   0.   1.   1.     1.    1

// So all subs of length 1 and 2 are always ignored, we only consider >=3