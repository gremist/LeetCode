// LeetCode 38 Count and Say.cpp

class Solution {
public:
    string countAndSay(int n) {
        string seq = "1";
        for (int i = 1; i < n; i++) {
            string new_seq;
            for (int j = 0, count = 1; j < seq.size(); j++, count++) {
                if (j + 1 >= seq.size() || seq[j] != seq[j + 1]) {
                    new_seq += count + '0';
                    new_seq += seq[j];
                    count = 0;
                }
            }
            seq = new_seq;
        }
        return seq;
    }
};