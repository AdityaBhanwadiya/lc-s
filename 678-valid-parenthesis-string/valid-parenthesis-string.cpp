class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStack;
        stack<int> starStack;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                openStack.push(i);
            } else if (s[i] == '*') {
                starStack.push(i);
            } else { // ')'
                if (!openStack.empty()) {
                    openStack.pop();
                } else if (!starStack.empty()) {
                    starStack.pop();
                } else {
                    return false;
                }
            }
        }

        while (!openStack.empty() && !starStack.empty()) {
            if (openStack.top() < starStack.top()) {
                openStack.pop();
                starStack.pop();
            } else {
                // '*' comes before '(', can't match
                return false;
            }
        }
        return openStack.empty();
    }
};

// So basic std rules, ( goes before ), if ( is present, there has to be )
// If above rule is satisfied but you gotta *, you can treat it as " ", else you can use that star as wild card and treat it as missign paranthesis for at most one time.
// (*))
// So () is good, * as ( so you satsified. 

// First thing that came to my haead is to count the braces individually
// open = 1, star = 1, close = 2
// But you cant get the order just by saving int ovariable.

// We can keep another var like if the open = 0 && star = 0 and you see close, return false.
// (()((*)))
// open = 4, close = 4, star = 1
// So in short close should be less than or eq to open + star else false
// (()**))))
// open = 2, star = 2 , close = 5

// what if its like this: (((***
// ***)))

// (**)
// So basically at teh end, open == close than irrespective of stars return true
// If open > close



// What if you use stack to check the order and quant of brackets ans just var for star?
// (()((*)))
// stack: 
// star: 1

// Gotta us 2 stacks