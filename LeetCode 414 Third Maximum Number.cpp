// LeetCode 414 Third Maximum Number.cpp

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> max_nums;
        for (int n : nums) {
            for (int &m : max_nums) {
                if (m == n) break;
                if (m  < n) swap(m, n);
            }
            if (max_nums.empty() ||
                max_nums.size() < 3 &&
                max_nums.back() > n) {
                max_nums.push_back(n);
            }
        }
        return max_nums[max_nums.size() < 3 ? 0 : 2];
    }
};