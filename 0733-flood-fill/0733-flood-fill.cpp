class Solution {
public:
    void dfsHelper(int i, int j, int originalColor, int color,
                   vector<vector<int>>& image) {
        
        int n = image.size();
        int m = image[0].size();

        // out of bounds or not original color
        if(i < 0 || i >= n || j < 0 || j >= m) return;
        
        if(image[i][j] != originalColor) return;

        image[i][j] = color;  // fill with new color

        // spread in all 4 directions
        dfsHelper(i-1, j, originalColor, color, image);
        dfsHelper(i+1, j, originalColor, color, image);
        dfsHelper(i, j-1, originalColor, color, image);
        dfsHelper(i, j+1, originalColor, color, image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, 
                                   int sr, int sc, int color) {
        
        int originalColor = image[sr][sc];

        // edge case - same color, nothing to do
        if(originalColor == color) return image;

        dfsHelper(sr, sc, originalColor, color, image);

        return image;
    }
};