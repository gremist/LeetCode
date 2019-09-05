// LeetCode 223 Rectangle Area.cpp

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a1 = (C - A) * (D - B);
        int a2 = (G - E) * (H - F);
        
        int l = max(A, E);
        int r = min(C, G);
        int b = max(B, F);
        int t = min(D, H);
        
        int overlap = 0;
        if (l < r && b < t) {
            overlap = (r - l) * (t - b);
        }
        return a1 + a2 - overlap;
    }
};