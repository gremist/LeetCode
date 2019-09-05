// LeetCode 1 Two Sum.cpp

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); i++) {
            if (index.find(nums[i]) != index.end()) {
                return {index[nums[i]], i};
            }
            index[target - nums[i]] = i;
        }
        throw logic_error("Unreachable code path");
    }
};