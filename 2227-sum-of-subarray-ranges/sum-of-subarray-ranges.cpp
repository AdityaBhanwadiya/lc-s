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

    vector<int> findNGE(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        // 3 1 2 4
        // st = 1 ,4 ,4 ,4
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }
    vector<int> findPGE(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        // 3 1 2 4
        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);

        long long total = 0, mod = 1e9+7;
        int left = 0, right = 0;

        for(int i=0;i<n;i++) {
            left = i-pse[i];
            right = nse[i]-i;
            total += 1LL * arr[i] * left * right;

        }
        return total;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse = findNGE(arr);
        vector<int> pse = findPGE(arr);

        long long total = 0, mod = 1e9+7;
        int left = 0, right = 0;

        for(int i=0;i<n;i++) {
            left = i-pse[i];
            right = nse[i]-i;
            total += 1LL * arr[i] * left * right;

        }
        return total;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};

// 1, 2, 3
// 1, 1 2, 1 2 3, 2, 2 3, 3
// 0, 1, 2, 0, 1, 0 = 4

// 1, 3, 3
// 1, 1 3, 1 3 3, 3, 3 3, 3
// 0, 2, 2, 0, 0, 0 = 4

