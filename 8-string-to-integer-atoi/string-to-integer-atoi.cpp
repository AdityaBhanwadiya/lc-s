class Solution {
// if space is leading than ignore, if its in between than return whatever in result string, if trailing then return result.
// If you encounter any random chars like a b c d then return result on spot
// if you encounter +/- before the numbers start then keep it else break and return whatever gathered in results.
//If found 0 before numbers, ignore, else keep it in result.

public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        long long result = 0;
        int sign = 1;

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // Handle sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Check for overflow
            if (sign * result <= INT_MIN) return INT_MIN;
            if (sign * result >= INT_MAX) return INT_MAX;

            i++;
        }

        return sign * result;
    }
};
