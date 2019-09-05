// LeetCode 709 To Lower Case.cpp

class Solution {
public:
    string toLowerCase(string str) {
        for (char &ch : str) {
            if (isupper(ch)) {
                ch += 'a' - 'A';
            }
        }
        return str;
    }
};