class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> gallo;
        
        for(auto it: bills) {
            //if its a $5 bill
            if(it == 5)
                gallo[it]++;
            
            // if its a $10, we need to give back something
            else if(it == 10){
                gallo[it]++;
                if(gallo[5] > 0) {
                    gallo[5]--;
                }else
                    return false;
            }

            // if its 20, do same shit
            else if(it == 20){
                gallo[it]++;
                if(gallo[5] > 0 && gallo[10] > 0) {
                    gallo[5]--;
                    gallo[10]--;
                }else if(gallo[5] > 2){
                    gallo[5] -= 3;
                }else
                    return false;
            }
        }
        return true;
    }
};

// So its like the give and take approach, we gotta keep a track of bills we have in the counter.
// bills = [5, 5, 10, 10, 20]
// So these are the bills that ith customer gave when purchasing a $5 stuff
// Lets create a map like that act as a counter to store the bills we get from the customers
// unordered_map -> 5: 0, 10: 0, 20: 0
// 5: 0, 10: 1, 20: 1
// So eveyr time there is a new bill coming in, you gotta check the change is present in the counter.



//[5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5]
// 5: 6, 10: 0, 20: 4