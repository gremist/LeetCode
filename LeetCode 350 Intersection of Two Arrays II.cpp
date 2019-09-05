// LeetCode 350 Intersection of Two Arrays II.cpp

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (int n : nums1) {
            m[n]++;
        }
        
        vector<int> ans;
        for (int n : nums2) {
            if (m.find(n) != m.end() && m[n] > 0) {
                ans.push_back(n);
                m[n]--;
            }
        }
        return ans;
    }
};