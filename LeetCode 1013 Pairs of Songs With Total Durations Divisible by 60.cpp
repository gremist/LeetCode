// LeetCode 1013 Pairs of Songs With Total Durations Divisible by 60.cpp

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        vector<int> ht(60, 0);
        for (int t : time) {
            ans += ht[(60 - t % 60) % 60];
            ht[t % 60]++;
        }
        return ans;
    }
};