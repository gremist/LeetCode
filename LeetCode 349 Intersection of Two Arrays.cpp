// LeetCode 349 Intersection of Two Arrays.cpp

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<int> ans;
        for (int n : s1) {
            if (s2.find(n) != s2.end()) {
                ans.push_back(n);
            }
        }
        return ans;
    }
};