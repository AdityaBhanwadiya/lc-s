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
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);

        long long total = 0, mod = 1e9+7;
        int left = 0, right = 0;

        for(int i=0;i<n;i++) {
            left = i-pse[i];
            right = nse[i]-i;
            total = (total + (right * left % mod * arr[i] % mod)) % mod;
        }
        return total;
    }
};