class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int maxOnes = 0;
        int currCount = 0;

        for(int i : nums) {
            if(i == 1){
                currCount++;
                maxOnes = max(maxOnes,currCount);
            } else{
                currCount = 0;
            }
        }
        return maxOnes;
    }
};