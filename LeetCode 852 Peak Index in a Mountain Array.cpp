// LeetCode 852 Peak Index in a Mountain Array.cpp

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int lo = 1, hi = A.size() - 2;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (A[mid] < A[mid + 1]) {
                lo = mid + 1;
            } else if (A[mid] < A[mid - 1]) {
                hi = mid - 1;
            } else {
                return mid;
            }
        }
        throw logic_error("Unreachable code path");
    }
};