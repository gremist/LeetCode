// LeetCode 961 N-Repeated Element in Size 2N Array.cpp

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> s;
        for (int a : A) {
            if (s.find(a) != s.end()) {
                return a;
            }
            s.insert(a);
        }
        throw logic_error("Unreachable code path");
    }
};