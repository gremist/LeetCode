// LeetCode 638 Shopping Offers.cpp

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ans = 0, n = price.size();
        for (int i = 0; i < n; i++) {
            ans += price[i] * needs[i];
        }
        for (vector<int> &sp : special) {
            int i;
            for (i = 0; i < n; i++) {
                if (needs[i] < sp[i]) {
                    break;
                }
            }
            if (i >= n) {
                for (int j = 0; j < n; j++) {
                    needs[j] -= sp[j];
                }
                ans = min(ans, shoppingOffers(price, special, needs) + sp[n]);
                for (int j = 0; j < n; j++) {
                    needs[j] += sp[j];
                }
            }
        }
        return ans;
    }
};