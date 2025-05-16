class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};

// abcde && cdeab

// lets say you rotated k times then the a should be at size of s - k + location of a
// lets say we did twice so a should be at 5-2+0 = 3 mode 5 = 3

// b should be at 5 - 2 + 1 = 4 mode 5 = 4
// c shoudl be at 5 - 2 + 2 = 5 mod 5 = 0
// d at 5 - 2 + 3 = 6 mod 5 = 1

// we can start of by cimparing first elemts

