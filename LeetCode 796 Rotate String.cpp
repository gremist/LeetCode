// LeetCode 796 Rotate String.cpp

class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != -1;
    }
};