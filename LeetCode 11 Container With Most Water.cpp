// LeetCode 11 Container With Most Water.cpp

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            max_area = max(max_area, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_area;
    }
};