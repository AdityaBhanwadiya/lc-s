// Applying bs on individual rows basd on last elem would boil down tc to O(n*logm)
// So we gotta treat the matrix as a single sorted array and then apply bs once so O(log(mn)).
// treat it as flat 1d array

// row can be found as idx/cols = 5/4 = 1
// col can be found as idx%cols = 5%4 = 1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0, right = rows*cols - 1;

        while(left <= right) {
            int mid = (left + right)/2;

            if(matrix[mid/cols][mid%cols] == target) {
                return true;
            }else if(matrix[mid/cols][mid%cols] < target) {
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return false;
    }
};