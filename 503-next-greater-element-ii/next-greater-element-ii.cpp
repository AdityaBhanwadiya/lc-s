class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;  // store indices

        for(int i = 0; i < 2 * n; i++) {
            int curr = nums[i % n];

            while(!st.empty() && nums[st.top()] < curr){
                res[st.top()] = curr;
                st.pop();
            }

            if(i < n) {
                st.push(i);
            }
        }
        return res;
    }
};

// 1 2 3 4 3 1 2 3 4
// 2 3 4


// So like after the last elem of given array assume there is extended array from 0 to that point - 1. 
// Lets say size = 5, so after extension it can go max of length 9
// so after 5 or 4th index, at 5th index it would be [5 % 5]th indexed element.
// At 6th it would be 6%5 th element and up till 9%5 it would 4th 