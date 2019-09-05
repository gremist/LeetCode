// LeetCode 832 Flipping an Image.cpp

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (vector<int> &row : A) {
            for (int i = 0; i < (row.size() + 1) / 2; i++) {
                if (row[i] == row[row.size() - i - 1]) {
                    row[i] = 1 - row[i];
                    row[row.size() - i - 1] = row[i];
                }
            }
        }
        return A;
    }
};