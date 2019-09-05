// LeetCode 811 Subdomain Visit Count.cpp

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (string &d : cpdomains) {
            int count = stoi(d);
            for (int i = d.size() - 1; d[i] != ' '; i--) {
                if (d[i - 1] == '.' || d[i - 1] == ' ') {
                    m[d.substr(i, d.size() - i)] += count;
                } 
            }
        }
        
        vector<string> ans(m.size());
        int i = 0;
        for (auto &p : m) {
            ans[i++] = to_string(p.second) + " " + p.first;
        }
        return ans;
    }
};