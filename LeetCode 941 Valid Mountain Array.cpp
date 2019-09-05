// LeetCode 941 Valid Mountain Array.cpp

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        bool top = false;
        for (int i = 0; i < A.size() - 1; i++) {
            top |= A[i] >= A[i + 1];
            if (top && (i == 0 || A[i] <= A[i + 1])) {
                return false;
            }
        }
        return top;
    }
};