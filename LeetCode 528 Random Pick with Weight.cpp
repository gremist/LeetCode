// LeetCode 528 Random Pick with Weight.cpp

class Solution {
public:
    Solution(vector<int>& w) : dre(time(0)), sum(w.size() + 1) {
        for (int i = 1; i < sum.size(); i++) {
            sum[i] = sum[i - 1] + w[i - 1];
        }
    }
    
    int pickIndex() {
        uniform_int_distribution<int> uid(0, sum.back() - 1);
        int lo = 0, hi = sum.size() - 2, n = uid(dre);
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (sum[mid] <= n) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }
    
private:
    default_random_engine dre;
    vector<int> sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */