// LeetCode 492 Construct the Rectangle.cpp

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int i = sqrt(area);
        while (area % i) {
            i--;
        }
        return {area / i, i};
    }
};