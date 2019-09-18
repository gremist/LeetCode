// LeetCode 313 Super Ugly Number.cpp

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n);
        ugly[0] = 1;
        
        vector<int> idx(primes.size());
        for (int i = 1; i < n; i++) {
            ugly[i] = ugly[idx[0]] * primes[0];
            for (int j = 1; j < idx.size(); j++) {
                ugly[i] = min(ugly[i], ugly[idx[j]] * primes[j]);
            }
            for (int j = 0; j < idx.size(); j++) {
                if (ugly[i] == ugly[idx[j]] * primes[j]) {
                    idx[j]++;
                }
            }
        }
        return ugly.back();
    }
};