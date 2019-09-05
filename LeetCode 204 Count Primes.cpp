LeetCode 204 Count Primes.cpp

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n - 2, true);
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (!prime[i - 2]) continue;
            for (int j = 2 * i; j < n; j += i) {
                prime[j - 2] = false;
            }
            cnt++;
        }
        return cnt;
    }
};