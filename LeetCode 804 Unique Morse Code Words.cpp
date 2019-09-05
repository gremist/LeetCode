// LeetCode 804 Unique Morse Code Words.cpp

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        for (string &word : words) {
            string morse;
            for (char ch : word) {
                morse += e2m[ch - 'a'];
            }
            s.insert(morse);
        }
        return s.size();
    }
    
private:
    vector<string> e2m = {".-", "-...", "-.-.",  "-..",    ".",
        "..-.",  "--.", "....",   "..", ".---",  "-.-", ".-..",
          "--",   "-.",  "---", ".--.", "--.-",  ".-.",  "...",
           "-",  "..-", "...-",  ".--", "-..-", "-.--", "--.."};
};