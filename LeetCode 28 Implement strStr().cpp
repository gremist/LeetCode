// LeetCode 28 Implement strStr().cpp

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = haystack.size() - needle.size() + 1;
        for (int i = 0, j; i < size; i++) {
            for (j = 0; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};