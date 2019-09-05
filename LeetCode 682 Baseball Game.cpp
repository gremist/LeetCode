// LeetCode 682 Baseball Game.cpp

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        for (string &str : ops) {
            switch (str.front()) {
            case '+':
                score.push_back(score.back() + score[score.size() - 2]);
                break;
            case 'D':
                score.push_back(2 * score.back());
                break;
            case 'C':
                score.pop_back();
                break;
            default:
                score.push_back(stoi(str));
            }
        }
        return accumulate(score.begin(), score.end(), 0);
    }
};