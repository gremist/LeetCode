// LeetCode 692 Top K Frequent Words.cpp

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string &w : words) {
            m[w]++;
        }
        
        auto comp = [&m] (pair<string, int> &pa, pair<string, int> &pb) {
            string &a = pa.first, &b = pb.first;
            return m[a] < m[b] || m[a] == m[b] && a > b;
        };
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> q(comp);
        for (auto &p : m) {
            q.push(p);
        }
        
        vector<string> ans(k);
        for (string &w : ans) {
            w = q.top().first;
            q.pop();
        }
        return ans;
    }
};