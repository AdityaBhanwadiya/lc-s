class Solution {
private:
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        // 3 1 2 4
        // st = 1 ,4 ,4 ,4
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }
    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        // 3 1 2 4
        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);
        int maxi = 0;

        for(int i=0;i<heights.size();i++) {
            maxi = max (maxi, (heights[i] * (nse[i] - pse[i] - 1)));
        }
        return maxi;
    }
};
