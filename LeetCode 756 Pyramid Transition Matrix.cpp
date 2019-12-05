// LeetCode 756 Pyramid Transition Matrix.cpp

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {        
        unordered_map<int, string> m;
        for (string &a : allowed) {
            m[a[0] << 8 | a[1]] += a[2];
        }
        return backtrack(m, bottom, 0, bottom.size() - 1);
    }

private:
    bool backtrack(unordered_map<int, string> &m, string &cur, int ci, int size) {
        if (ci >= size && (!--size || (ci = 0))) return true;
        for (char ch : m[cur[ci] << 8 | cur[ci + 1]]) {
            swap(cur[ci], ch);
            if (backtrack(m, cur, ci + 1, size)) {
                return true;
            }
            swap(cur[ci], ch);
        }
        return false;
    }
};