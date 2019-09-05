// LeetCode 278 First Bad Version.cpp

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (!isBadVersion(mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};