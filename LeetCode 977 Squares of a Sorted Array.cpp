// LeetCode 977 Squares of a Sorted Array.cpp

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans(A.size());
        int l = 0, r = A.size() - 1;
        while (l <= r) {
            if (A[l] + A[r] < 0) {
                ans[r - l] = A[l] * A[l];
                l++;
            } else {
                ans[r - l] = A[r] * A[r];
                r--;
            }
        }
        return ans;
    }
};