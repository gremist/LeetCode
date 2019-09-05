// LeetCode 989 Add to Array-Form of Integer.cpp

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ans;
        int i = A.size() - 1;
        while (i >= 0 || K) {
            if (i >= 0) {
                K += A[i--];
            }
            ans.push_back(K % 10);
            K /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};