// LeetCode 239 Sliding Window Maximum.cpp

// 方法1：暴力法
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        if (k == 1) return nums;
        vector<int> ans(nums.size() - k + 1);
        for (int i = 0; i < ans.size(); i++) {
            if (i > 0 && nums[i + k - 1] >= ans[i - 1]) {
                ans[i] = nums[i + k - 1];
            } else if (i > 0 && ans[i - 1] > nums[i - 1]) {
                ans[i] = ans[i - 1];
            } else {
                ans[i] = *max_element(nums.begin() + i, nums.begin() + i + k);
            }
        }
        return ans;
    }
};

// 方法2：单调队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        if (k == 1) return nums;
        vector<int> ans(nums.size() - k + 1);
        deque<int> d;
        for (int i = 0; i < nums.size(); i++) {
            while (!d.empty() && d.back() < nums[i]) {
                d.pop_back();
            }
            d.push_back(nums[i]);
            if (i >= k - 1) {
                ans[i - k + 1] = d.front();
                if (d.front() == nums[i - k + 1]) {
                    d.pop_front();
                }
            }
        }
        return ans;
    }
};