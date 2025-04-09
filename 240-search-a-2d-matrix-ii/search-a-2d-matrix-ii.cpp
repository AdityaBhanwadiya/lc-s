class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(); // 5
        int c = matrix[0].size(); // 5

        int row = 0, col = c-1; // 0, 4

        while(row < r && col >=0) {
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target) {
                col--;
            }else
                row++;
        }
        return false;

    }
};