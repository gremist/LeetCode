// LeetCode 13 Roman to Integer.cpp

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, num = 0;
        for (char r : s) {
            ans += mapr2i[r] > num ? -num : num;
            num  = mapr2i[r];
        }
        return ans + num;
    }

private:
    unordered_map<char, int> mapr2i = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
};