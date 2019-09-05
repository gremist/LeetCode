// LeetCode 202 Happy Number.cpp

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n > 1) {
            s.insert(n);
            
            int new_n = 0;
            while (n) {
                new_n += pow(n % 10, 2);
                n /= 10;
            }
            
            if (s.find(new_n) != s.end()) {
                return false;
            }
            n = new_n;
        }
        return true;
    }
};