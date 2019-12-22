// LeetCode 1282 Group the People Given the Group Size They Belong To.cpp

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, int> m;
        for (int i = 0; i < groupSizes.size(); i++) {
            if (m.find(groupSizes[i]) == m.end() || ans[m[groupSizes[i]]].size() >= groupSizes[i]) {
                ans.emplace_back();
                m[groupSizes[i]] = ans.size() - 1;
            }
            ans[m[groupSizes[i]]].push_back(i);
        }
        return ans;
    }
};