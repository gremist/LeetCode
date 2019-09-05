// LeetCode 735 Asteroid Collision.cpp

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (int ast : asteroids) {
            if (ast < 0) {
                while (!s.empty() && 0 < s.back() && s.back() < -ast) {
                    s.pop_back();
                }
                if (s.empty() || s.back() < 0) {
                    s.push_back(ast);
                } else if (s.back() == -ast) {
                    s.pop_back();
                }
            } else {
                s.push_back(ast);
            }
        }
        return s;
    }
};