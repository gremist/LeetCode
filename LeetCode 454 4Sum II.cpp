// LeetCode 454 4Sum II.cpp

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> index;
        for (int a : A) {
            for (int b : B) {
                index[-a - b]++;
            }
        }
        
        int ans = 0;
        for (int c : C) {
            for (int d : D) {
                if (index.find(c + d) != index.end()) {
                    ans += index[c + d];
                }
            }
        }
        return ans;
    }
};