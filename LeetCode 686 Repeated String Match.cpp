// LeetCode 686 Repeated String Match.cpp

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int as = A.size(), bs = B.size();
        string nA = A;
        while (nA.size() < as + bs) {
            nA += A;
        }
        int i = nA.find(B);
        return i != -1 ? (i + bs - 1) / as + 1 : -1;
    }
};