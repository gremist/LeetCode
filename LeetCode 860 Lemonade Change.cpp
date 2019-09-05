// LeetCode 860 Lemonade Change.cpp

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0;
        for (int b : bills) {
            switch (b) {
            case 5:
                c5++;
                break;
            case 10:
                if (c5 > 0) {
                    c5--;
                    c10++;
                } else {
                    return false;
                }
                break;
            case 20:
                if (c5 > 0 && c10 > 0) {
                    c5--;
                    c10--;
                } else if (c5 > 2) {
                    c5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};