class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lt, gt;
        int eq = 0;

        for(auto it : nums){
            if(it < pivot)  lt.push_back(it);
            if(it > pivot)  gt.push_back(it);
            if(it == pivot) eq++;
        }
        nums.clear();

        for(auto it: lt) nums.push_back(it);
        while(eq > 0) {
            nums.push_back(pivot);
            eq--;
        }
        for(auto it: gt) nums.push_back(it);

        return nums;

    }
};