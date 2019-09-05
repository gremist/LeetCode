// LeetCode 374 Guess Number Higher or Lower.cpp

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int ans = guess(mid);
            if (ans > 0) {
                low = mid + 1;
            } else if (ans < 0) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        throw logic_error("Unreachable code path");
    }
};