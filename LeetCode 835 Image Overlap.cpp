// LeetCode 835 Image Overlap.cpp

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int max_overlap = 0, n = A.size();
        vector<vector<int>> slide(2 * n - 1, vector<int>(2 * n - 1));
        for (int ai = 0; ai < n; ai++) {
            for (int aj = 0; aj < n; aj++) {
                if (A[ai][aj]) {
                    for (int bi = 0; bi < n; bi++) {
                        for (int bj = 0; bj < n; bj++) {
                            if (B[bi][bj]) {
                                max_overlap = max(max_overlap, ++slide[ai - bi + n - 1][aj - bj + n - 1]);
                            }
                        }
                    }
                }
            }
        }
        return max_overlap;
    }
};