// LeetCode 274 H-Index.cpp

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        vector<int> bucket(size + 1);
        for (int ci : citations) {
            bucket[min(ci, size)]++;
        }
        for (int i = size, sum = 0; i > 0; i--) {
            sum += bucket[i];
            if (sum >= i) {
                return i;
            }
        }
        return 0;
    }
};