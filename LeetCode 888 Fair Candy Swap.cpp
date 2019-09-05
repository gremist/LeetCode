// LeetCode 888 Fair Candy Swap.cpp

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int delta = (accumulate(B.begin(), B.end(), 0) -
            accumulate(A.begin(), A.end(), 0)) / 2;
        unordered_set<int> s(B.begin(), B.end());
        for (int a : A) {
            if (s.find(a + delta) != s.end()) {
                return {a, a + delta};
            }
        }
        throw logic_error("Unreachable code path");
    }
};