class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }   
        vector<int> nos;
        int zeros = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 0)
                zeros++;
            else
                nos.push_back(nums[i]);
        }

        nums.clear();

        for(int i=0;i<nos.size();i++)
            nums.push_back(nos[i]);
        
        for(int i=0;i<zeros;i++)
            nums.push_back(0);


        return nums;
    }
};