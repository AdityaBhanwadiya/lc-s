class Solution {
public:
    unordered_map<string, bool> yaad; // Memoization map

    bool madad(string s, string p, int i, int j) {
        string key = to_string(i) + "," + to_string(j);
        if (yaad.count(key)) return yaad[key]; // Check memo

        if (j == p.size()) return i == s.size(); // Base case
        
        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            return yaad[key] = madad(s, p, i, j + 2) ||  // Ignore `p[j]*`
                               (match && madad(s, p, i + 1, j)); // Use `p[j]`
        }

        return yaad[key] = match && madad(s, p, i + 1, j + 1);
    }

    bool isMatch(string s, string p) {
        return madad(s, p, 0, 0);
    }
};
