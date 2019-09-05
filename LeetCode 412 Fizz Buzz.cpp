// LeetCode 412 Fizz Buzz.cpp

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> r_vec(n);
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                r_vec[i - 1] = "FizzBuzz";
            } else if (i % 3 == 0) {
                r_vec[i - 1] = "Fizz";
            } else if (i % 5 == 0) {
                r_vec[i - 1] = "Buzz";
            } else {
                r_vec[i - 1] = to_string(i);
            }
        }
        return r_vec;
    }
};