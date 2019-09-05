// LeetCode 287 Find the Duplicate Number.cpp

// 方法1：排序
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }
        throw logic_error("Unreachable code path");
    }
};

// 方法2：哈希表
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums) {
            if (s.find(n) != s.end()) {
                return n;
            }
            s.insert(n);
        }
        throw logic_error("Unreachable code path");
    }
};

// 方法3：快慢指针
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (0 <= fast && fast < nums.size() &&
               0 <= nums[fast] && nums[fast] < nums.size()) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                fast = 0;
                while (slow != fast) {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return fast;
            }
        }
        throw logic_error("Unreachable code path");
    }
};