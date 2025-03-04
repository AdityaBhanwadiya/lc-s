class Solution {
private:
    // prev smaller element
    vector<int> prevSmallerElement(vector<int>& nums2) {
        stack<int> st;
        int m = nums2.size();
        vector<int> ans(m);

        for(int i = 0; i < m; i++) {
            while (!st.empty() && nums2[st.top()] >= nums2[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);  
        }   
        return ans;
    }

    // next smaller element
    vector<int> nextSmallerElement(vector<int>& nums2) {
        stack<int> st;
        int m = nums2.size();
        int i = m - 1;
        vector<int> ans(m);

        while (i >= 0) {
            while (!st.empty() && nums2[st.top()] >= nums2[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? m : st.top(); 
            st.push(i); 
            i--;
        }   
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = nextSmallerElement(heights);
        vector<int> pse = prevSmallerElement(heights);

        int maxi = 0;
        for(int i = 0; i < heights.size(); i++) {
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;
    }
};
