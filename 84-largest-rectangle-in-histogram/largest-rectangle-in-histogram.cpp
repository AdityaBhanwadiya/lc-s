class Solution {
private:
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

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
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();

        stack<int> st;
        int maxArea = 0;

        for(int i=0;i<n;i++) {
            while(!st.empty() && arr[st.top()] > arr[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, arr[element] * (nse - pse - 1));

            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            int element = st.top();st.pop();
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, arr[element] * (nse - pse - 1));

        }
        return maxArea;
    }
};



// to do it one pass, we cant store the pre computed values of nse ans pse, we gotta do it on fly!
// We take a stack, go on putting in but when you encounter the smaller one compared to top, you know that it is the nse of that top element! 
// At that time you touch that element and calculate using formula we did previously.
// So for pse, we say that we are doing onfly ops for pse.

// Eg: 3 2 10 11 5 10 6 3
// Stack ind: 0
// Now stack has 3, so when at 2, 3 (top) is not pse of 2, so we kick out but remember, to apply formula
// 3 * (1 - (-1) - 1) = 3 so stack ins: 1
// Now we are at 10, 10 > 2, so push: stack : 1, 2
// Now we are at 11, 11 > 10, so push: stack : 1, 2, 3
// Now we are at 5, 5 < 11, so we backtrack with nse. so we can say that 5 is. nse of 11! pse of 11 is already in stack that is the element before 11. So we got pse = 10, nse = 11 hence 11 * (4 - 2 - 1) = 11, pop 11 from stack, so we have: 1, 2
// Now, we still at 5 so same stuff again, 5 is nse of 10 and 2 is pse of 10, so 10 * (4 - 1 - 1) = 20, pop 10
// stack now has 1, we put val 5 so 1, 4
// stack: 1, 4, 5
// This goes on