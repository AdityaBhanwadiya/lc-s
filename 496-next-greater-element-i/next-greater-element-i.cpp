class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums1.size();
        int m = nums2.size();
        int i = m-1;
        unordered_map<int, int> myMap;

        while(i >= 0) {
            if(st.empty())  {
                myMap[nums2[i]] = -1;
            }else{
                if(st.top() > nums2[i]){
                    myMap[nums2[i]] = st.top();
                }else{
                    while(!st.empty() && st.top() < nums2[i]) {
                        st.pop();
                    }
                    myMap[nums2[i]] = st.empty() ? -1 : st.top();
                }
            }
            st.push(nums2[i]);
            i--;
        }   

        vector<int> ans;

        for(auto it : nums1){
            if(myMap.find(it) != myMap.end()){
                ans.push_back(myMap[it]);
            }
        }
        return ans;
    }
};