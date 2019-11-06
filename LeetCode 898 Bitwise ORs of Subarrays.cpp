// LeetCode 898 Bitwise ORs of Subarrays.cpp

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> s;
        int max_val = 0;
        for (int a : A) {
            max_val |= a;
            s.insert(max_val);
        }
        for (int i = 1; i < A.size(); i++) {
            for (int j = i, val = 0; j < A.size(); j++) {
                val |= A[j];
                if (val == max_val) {
                    break;
                }
                s.insert(val);
            }
        }
        return s.size();
    }
};