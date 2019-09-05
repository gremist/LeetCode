// LeetCode 3 Longest Substring Without Repeating Characters.cpp

// 方法1：顺序查找
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        for (int i = 0, last = -1; i < s.size(); i++) {
            for (int j = last + 1; j < i; j++) {
                if (s[i] == s[j]) {
                    last = j;
                    break;
                }
            }
            max_len = max(i - last, max_len);
        }
        return max_len;
    }
};

// 方法2：哈希表
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        vector<int> ht(128, -1);
        for (int i = 0, last = -1; i < s.size(); i++) {
            last = max(ht[s[i]], last);
            max_len = max(i - last, max_len);
            ht[s[i]] = i;
        }
        return max_len;
    }
};