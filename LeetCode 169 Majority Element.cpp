// LeetCode 169 Majority Element.cpp

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            if (++m[n] > nums.size() / 2) {
                return n;
            }
        }
        throw logic_error("Unreachable code path");
    }
};