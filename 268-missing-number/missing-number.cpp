class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> myMap;
        for(auto it:nums){
            myMap[it] = 1;
        }
        for(int i=0;i<=nums.size();i++) {
            if(myMap.find(i) == myMap.end()){
                return i;
            }
        }
        return -1;
    }
};