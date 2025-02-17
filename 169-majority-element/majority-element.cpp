class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int number = 0;
        int count = 0;

        for(int i=0;i<n;i++){
            if(count == 0){
                number = nums[i];
                count=1;
            }else if(nums[i] == number){
                count++;
            }
            else{
                count--;
            }
        }

        int cnt1 = 0;
        for(auto it : nums) {
            if(it == number)
                cnt1++;
        }

        if(cnt1 > n/2)
            return number;
        return -1;
    }
};