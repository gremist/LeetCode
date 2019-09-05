// LeetCode 398 Random Pick Index.cpp

class Solution {
public:
    Solution(vector<int>& nums) : dre(time(0)), nums(nums) {
        
    }
    
    int pick(int target) {
        int ans;
        for (int i = 0, count = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                uniform_int_distribution<int> uid(0, count++);
                if (!uid(dre)) {
                    ans = i;
                }
            }
        }
        return ans;
    }
    
private:
    default_random_engine dre;
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */