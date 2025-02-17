class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> result;

        for(auto it : nums){
            if(it > 0)  pos.push_back(it);
            else    neg.push_back(it);
        }

        int posIndex = 0, negIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) result.push_back(pos[posIndex++]);
            else result.push_back(neg[negIndex++]); 
        }

        return result;
    }
};