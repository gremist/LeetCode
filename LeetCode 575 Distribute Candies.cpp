// LeetCode 575 Distribute Candies.cpp

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        return min(unordered_set<int>(candies.begin(), candies.end()).size(), candies.size() / 2);
    }
};