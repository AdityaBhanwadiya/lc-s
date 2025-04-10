class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        for(int i=0;i<rows;i++) {
            int left = i, right = mat[i].size();

            while(left<= right) {
                int mid = left + (right - left) / 2;

                // Find max element's row in this column
                int maxRow = 0;
                for(int i = 1; i < rows; i++) {
                    if(mat[i][mid] > mat[maxRow][mid]) {
                        maxRow = i;
                    }
                }

                int maxValueInRow = mat[maxRow][mid];
                int leftVal  = (mid - 1 >= 0)     ? mat[maxRow][mid - 1] : -1;
                int rightVal = (mid + 1 < cols)   ? mat[maxRow][mid + 1] : -1;

                if(maxValueInRow > leftVal && maxValueInRow > rightVal) {
                    return {maxRow, mid};
                } else if(rightVal > maxValueInRow) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }

            }
        }
        return {-1, -1};
    }
};