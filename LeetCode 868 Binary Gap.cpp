// LeetCode 868 Binary Gap.cpp

class Solution {
public:
    int binaryGap(int N) {
        int max_gap = 0;
        for (int i = 0, last = -1; i < 8 * sizeof(int); i++) {
            if (N >> i & 1) {
                if (last >= 0) {
                    max_gap = max(max_gap, i - last);
                }
                last = i;
            }
        }
        return max_gap;
    }
};