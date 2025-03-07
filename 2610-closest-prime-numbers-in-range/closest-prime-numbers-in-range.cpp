class Solution {
private:
    vector<bool> sieve(int n) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        return is_prime;
    }
public:
    // first find all primes using some algo I think its O(n)
    // 11 13 17 19 -> Space O(n)
    // it can be any 2 consecutives so n-1 checks O(n)
    // Find the lowest amongst it 
    vector<int> closestPrimes(int left, int right) {
        vector<bool> is_prime = sieve(right);
        vector<int> primes;

        for (int i = left; i <= right; i++) {
            if (is_prime[i]) primes.push_back(i);
        }

        if (primes.size() < 2) return {-1, -1};

        int min_gap = INT_MAX;
        vector<int> result = {-1, -1};
        
        for (size_t i = 1; i < primes.size(); i++) {
            int gap = primes[i] - primes[i - 1];
            if (gap < min_gap) {
                min_gap = gap;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
        }
};