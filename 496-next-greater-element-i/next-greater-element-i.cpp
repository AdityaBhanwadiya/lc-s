class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> myMap;

        stack<int> st;

        vector<int> result;
        for(int i=0;i<nums2.size();i++) {
            if(st.empty()){
                st.push(nums2[i]);
            }else{
                while(!st.empty() && nums2[i] > st.top()){
                    myMap[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }

        while(!st.empty()){
            myMap[st.top()] = -1;
            st.pop();
        }

        for(auto it:nums1){
            if(myMap.find(it) != myMap.end()){
                result.push_back(myMap[it]);
            }
        }
        return result;
    }
};

