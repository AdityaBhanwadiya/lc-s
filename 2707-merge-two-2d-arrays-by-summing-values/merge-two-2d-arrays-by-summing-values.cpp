class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> ans;

        int i=0, j=0;

        while(i < n && j < m) {
            vector<int> temp;

            auto it1 = nums1[i];
            auto it2 = nums2[j];

            if(it1[0] == it2[0]){
                temp.push_back(it1[0]);
                temp.push_back(it1[1] + it2[1]);

                i++;j++;
            } else if(it1[0] < it2[0]) {
                temp = it1;
                i++;
            } else {
                temp = it2;
                j++;
            }

            ans.push_back(temp);
        }

        if(i < n){
            while(i < n){
                auto rem = nums1[i];
                ans.push_back(rem);
                i++;
            }
        }else{
            while(j < m){
                auto rem = nums2[j];
                ans.push_back(rem);
                j++;
            }
        }

        return ans;
    }
};