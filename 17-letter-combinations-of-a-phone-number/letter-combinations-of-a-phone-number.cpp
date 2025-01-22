class Solution {
public:
    unordered_map<char, string> buttons;

    Solution() {  
        buttons['2'] = "abc";
        buttons['3'] = "def";
        buttons['4'] = "ghi";
        buttons['5'] = "jkl";
        buttons['6'] = "mno";
        buttons['7'] = "pqrs";
        buttons['8'] = "tuv";
        buttons['9'] = "wxyz";
    }

    void backtrack(vector<string>& matchingStrings, string current, int pos, vector<string>& result) {
        if (pos == matchingStrings.size()) {
            result.push_back(current);
            return;
        }

        string possibleLetters = matchingStrings[pos];
        for (char letter : possibleLetters) {
            backtrack(matchingStrings, current + letter, pos + 1, result);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;  
        vector<string> matchingStrings;  

        if (digits.empty()) return result;

        for (char digit : digits) {
            if (buttons.find(digit) != buttons.end()) {
                matchingStrings.push_back(buttons[digit]);
            }
        }

        backtrack(matchingStrings, "", 0, result);
        return result;
    }
};
