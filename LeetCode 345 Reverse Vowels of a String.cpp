// LeetCode 345 Reverse Vowels of a String.cpp

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("AEIOUaeiou", i);
            j = s.find_last_of("AEIOUaeiou", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};