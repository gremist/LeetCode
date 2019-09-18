// LeetCode 748 Shortest Completing Word.cpp

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> ht1(26);
        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                ht1[tolower(ch) - 'a']++;
            }
        }
        
        int wi = -1;
        for (int i = 0, j; i < words.size(); i++) {
            if (wi != -1 && words[i].size() >= words[wi].size()) {
                continue;
            }
            
            vector<int> ht2(26);
            for (char ch : words[i]) {
                ht2[ch - 'a']++;
            }
            
            for (j = 0; j < 26; j++) {
                if (ht1[j] > ht2[j]) {
                    break;
                }
            }
            if (j >= 26) {
                wi = i;
            }
        }
        return words[wi];
    }
};