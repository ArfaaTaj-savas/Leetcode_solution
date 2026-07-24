class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();

        for (int row = rows - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                triangle[row][col] += min(triangle[row + 1][col],
                                          triangle[row + 1][col + 1]);
            }
        }

        return triangle[0][0];
    }
};