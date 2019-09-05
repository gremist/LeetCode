// LeetCode 4 Median of Two Sorted Arrays.cpp

// 方法1：顺序查找
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        if (s1 > s2) return findMedianSortedArrays(nums2, nums1);
        
        int half = (s1 + s2) / 2;
        for (int i = 0; i <= s1; i++) {
            int j = half - i;
            if (i >= s1 || nums1[i] >= nums2[j - 1]) {
                int x = i < s1 ? j < s2 ? min(nums1[  i], nums2[  j]) : nums1[  i] : nums2[  j];
                int y = i >  0 ? j >  0 ? max(nums1[i-1], nums2[j-1]) : nums1[i-1] : nums2[j-1];
                return (s1 + s2) % 2 ? x : (x + y) / 2.0;
            }
        }
        throw logic_error("Unreachable code path");
    }
};

// 方法2：二分查找
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        if (s1 > s2) return findMedianSortedArrays(nums2, nums1);
        
        int lo = 0, hi = s1, half = (s1 + s2) / 2;
        while (lo <= hi) {
            int i = (lo + hi) / 2;
            int j = half - i;
            if (i < hi && nums1[i] < nums2[j - 1]) {
                lo = i + 1;
            } else if (i > lo && nums1[i - 1] > nums2[j]) {
                hi = i - 1;
            } else {
                int x = i < s1 ? j < s2 ? min(nums1[  i], nums2[  j]) : nums1[  i] : nums2[  j];
                int y = i >  0 ? j >  0 ? max(nums1[i-1], nums2[j-1]) : nums1[i-1] : nums2[j-1];
                return (s1 + s2) % 2 ? x : (x + y) / 2.0;
            }
        }
        throw logic_error("Unreachable code path");
    }
};