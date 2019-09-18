// LeetCode 475 Heaters.cpp

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int ans = 0;
        for (int i = 0, j = 0; i < houses.size(); i++) {
            while (j < heaters.size() && houses[i] > heaters[j]) {
                j++;
            }
            int lr = j > 0 ? houses[i] - heaters[j - 1] : INT_MAX;
            int rr = j < heaters.size() ? heaters[j] - houses[i] : INT_MAX;
            ans = max(ans, min(lr, rr));
        }
        return ans;
    }
};