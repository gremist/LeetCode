// LeetCode 771 Jewels and Stones.cpp

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<bool> ht(128);
        for (char &ch : J) {
            ht[ch] = true;
        }
        int cnt = 0;
        for (char &ch : S) {
            if (ht[ch]) {
                cnt++;
            }
        }
        return cnt;
    }
};