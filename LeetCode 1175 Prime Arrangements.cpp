// LeetCode 1175 Prime Arrangements.cpp

class Solution {
public:
    int numPrimeArrangements(int n) {
        int cnt = 0, ans = 1;
        vector<bool> prime(n + 1, true);
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                for (int j = 2 * i; j <= n; j += i) {
                    prime[j] = false;
                }
                cnt++;
            }
        }
        for (int i = 2; i <= cnt; i++) {
            ans = 1l * ans * i % 1000000007;
        }
        for (int i = 2; i <= n - cnt; i++) {
            ans = 1l * ans * i % 1000000007;
        }
        return ans;
    }
};