class Solution {
public:
    // 12 / 3 = 4
    //if(4%3 == 1)
    // 4/3 = 1
    // if(1%3 == 1)
    // 1/3 = 0 --> return true

    // 21/3 = 7
    // if(7%3 == 1)
    // 7/3 = 2
    //if(2%3 == 2)  return false

    // 91/3 = 30
    // if(91%3 == 1)


    bool checkPowersOfThree(int n) {
        while(n > 0){
            if(n%3 == 2)    return false;
            n = n/3;
        }
        return true;
    }
};