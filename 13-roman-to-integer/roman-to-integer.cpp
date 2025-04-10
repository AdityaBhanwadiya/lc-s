class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> convs;
        convs["I"] = 1;
        convs["V"] = 5;
        convs["X"] = 10;
        convs["L"] =50;
        convs["C"] = 100;
        convs["D"] = 500;
        convs["M"] = 1000;
        convs["IV"] = 4;
        convs["IX"] = 9;
        convs["XL"] = 40;
        convs["XC"] = 90;
        convs["CD"] = 400;
        convs["CM"] = 900;


        int num = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i] == 'I'){
                if(s[i+1] == 'V' || s[i+1] == 'X') {
                    num += convs[s.substr(i, 2)];
                    i++;
                } else{
                    num += convs[s.substr(i, 1)];
                }
            }
            else if(s[i] == 'X'){
                if(s[i+1] == 'L' || s[i+1] == 'C') {
                    num += convs[s.substr(i, 2)];
                    i++;
                } else{
                    num += convs[s.substr(i, 1)];
                }
            }
            else if(s[i] == 'C'){
                if(s[i+1] == 'D' || s[i+1] == 'M') {
                    num += convs[s.substr(i, 2)];
                    i++;
                } else{
                    num += convs[s.substr(i, 1)];
                }
            }else{
                num += convs[s.substr(i, 1)];
            }
        }
        return num;
    }


};


// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// IV -> 4
// IX -> 9

// XL -> 40
// XC -> 90

// CD -> 400
// CM -> 900

//MCMXCIV
//M + CM + XC + IV = 1000 + 900 + 90 + 4 = 1994