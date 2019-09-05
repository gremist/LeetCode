// LeetCode 347 Top K Frequent Elements.cpp

// 方法1：优先队列
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
        }
        
        priority_queue<pair<int, int>> q;
        for (auto &pair : m) {
            int n = pair.first;
            q.emplace(m[n], n);
        }
        
        vector<int> ans(k);
        for (int &n : ans) {
            n = q.top().second;
            q.pop();
        }
        return ans;
    }
};

// 方法2：计数排序
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
        }
        
        vector<vector<int>> count(nums.size());
        for (auto &pair : m) {
            int n = pair.first;
            count[m[n] - 1].push_back(n);
        }
        
        vector<int> ans(k);
        int i = count.size() - 1, j = 0;
        for (int &n : ans) {
            while (j >= count[i].size()) {
                i--;
                j = 0;
            }
            n = count[i][j++];
        }
        return ans;
    }
};