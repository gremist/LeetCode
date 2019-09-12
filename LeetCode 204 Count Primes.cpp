// LeetCode 204 Count Primes.cpp

class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> prime(n, true);
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                for (int j = 2 * i; j < n; j += i) {
                    prime[j] = false;
                }
                cnt++;
            }
        }
        return cnt;
    }
};