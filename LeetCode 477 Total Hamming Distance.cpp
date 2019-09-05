// LeetCode 477 Total Hamming Distance.cpp

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int dist = 0;
        for (int i = 0; i < 8 * sizeof(int); i++) {
            int b1 = 0;
            for (int n : nums) {
                b1 += n >> i & 1;
            }
            dist += b1 * (nums.size() - b1);
        }
        return dist;
    }
};