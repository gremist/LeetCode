// LeetCode 1103 Distribute Candies to People.cpp

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        for (int i = 0; candies > 0; candies -= ++i) {
            ans[i % num_people] += min(i + 1, candies);
        }
        return ans;
    }
};