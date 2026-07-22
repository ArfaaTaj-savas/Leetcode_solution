class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int oldColor, int newColor) {
        int rows = image.size();
        int cols = image[0].size();

        if (row < 0 || col < 0 || row >= rows || col >= cols)
            return;

        if (image[row][col] != oldColor)
            return;

        image[row][col] = newColor;

        dfs(image, row - 1, col, oldColor, newColor);
        dfs(image, row + 1, col, oldColor, newColor);
        dfs(image, row, col - 1, oldColor, newColor);
        dfs(image, row, col + 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        if (oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};
