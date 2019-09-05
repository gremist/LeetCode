// LeetCode 458 Poor Pigs.cpp

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return (int)ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};