// LeetCode 733 Flood Fill.cpp

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int baseColor, int newColor) {
        if (sr < 0 || sr >= image.size()) return;
        if (sc < 0 || sc >= image[0].size()) return;
        if (image[sr][sc] != baseColor) return;
        
        image[sr][sc] = newColor;
        
        dfs(image, sr - 1, sc, baseColor, newColor);
        dfs(image, sr + 1, sc, baseColor, newColor);
        dfs(image, sr, sc - 1, baseColor, newColor);
        dfs(image, sr, sc + 1, baseColor, newColor);
    }
};