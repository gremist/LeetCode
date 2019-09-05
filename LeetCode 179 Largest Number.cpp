// LeetCode 179 Largest Number.cpp

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            v[i] = to_string(nums[i]);
        }
        
        sort(v.begin(), v.end(),
             [] (string &a, string &b) { return a + b > b + a; });
        
        if (v[0] == "0") {
            return "0";
        }
        
        string ans;
        for (string &s : v) {
            ans += s;
        }
        return ans;
    }
};