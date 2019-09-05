// LeetCode 12 Integer to Roman.cpp

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        while (num > 0) {
            auto it = mapi2r.lower_bound(num);
            num -= it->first;
            ans += it->second;
        }
        return ans;
    }

private:
    map<int, string, greater<int>> mapi2r = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
};