// LeetCode 209 Minimum Size Subarray Sum.cpp

// 方法1：遍历 + 顺序查找，T(n) = O(n^2)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> sum(nums.size() + 1, 0);
        for (int i = 1; i < sum.size(); i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        if (sum.back() <  s) return 0;
        if (sum.back() == s) return nums.size();
        
        int min_len = nums.size() + 1;
        for (int i = 0; i < sum.size() - 1; i++) {
            int range = min(i + min_len, (int)sum.size());
            for (int j = i + 1; j < range; j++) {
                if (sum[j] - sum[i] >= s) {
                    min_len = j - i;
                    break;
                }
            }
        }
        return min_len;
    }
};

// 方法2：遍历 + 二分查找，T(n) = O(nlogn)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> sum(nums.size() + 1, 0);
        for (int i = 1; i < sum.size(); i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        if (sum.back() <  s) return 0;
        if (sum.back() == s) return nums.size();
        
        int min_len = nums.size() + 1;
        for (int i = 0; i < sum.size() - 1; i++) {
            int range = min(i + min_len, (int)sum.size());
            int lo = i + 1, hi = range - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (sum[mid] - sum[i] < s) {
                    lo = mid + 1;
                } else if (sum[mid] - sum[i] > s) {
                    hi = mid - 1;
                } else {
                    lo = mid;
                    break;
                }
            }
            if (lo < range) {
                min_len = lo - i;
            }
        }
        return min_len;
    }
};

// 方法3：滑动窗口，T(n) = O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int min_len = nums.size() + 1;
        int l = 0, r = 0, sum = 0;
        while (r < nums.size()) {
            sum += nums[r++];
            while (sum >= s) {
                min_len = min(r - l, min_len);
                sum -= nums[l++];
            }
        }
        return min_len > nums.size() ? 0 : min_len;
    }
};