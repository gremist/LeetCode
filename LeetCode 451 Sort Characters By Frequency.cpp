// LeetCode 451 Sort Characters By Frequency.cpp

// 方法1：优先队列，T(n) = O(nlogk)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (char ch : s) {
            m[ch]++;
        }
        
        priority_queue<pair<int, char>> q;
        for (auto &pair : m) {
            char ch = pair.first;
            q.emplace(m[ch], ch);
        }
        
        string ans;
        for (int i = 0, n = q.size(); i < n; i++) {
            char ch = q.top().second;
            q.pop();
            ans.append(m[ch], ch);
        }
        return ans;
    }
};

// 方法2：计数排序，T(n) = O(n+k)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (char ch : s) {
            m[ch]++;
        }
        
        vector<string> count(s.size());
        for (auto &pair : m) {
            char ch = pair.first;
            count[m[ch] - 1].append(m[ch], ch);
        }
        
        string ans;
        for (int i = count.size() - 1; i >= 0; i--) {
            ans += count[i];
        }
        return ans;
    }
};