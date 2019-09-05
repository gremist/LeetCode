// LeetCode 220 Contains Duplicate III.cpp

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }
            auto it = s.lower_bound((long)nums[i] - t);
            if (it != s.end() && *it - nums[i] <= t) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};