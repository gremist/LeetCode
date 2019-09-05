// LeetCode 217 Contains Duplicate.cpp

// 方法1：查找
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.find(num) != s.end()) {
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};

// 方法2：统计
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};