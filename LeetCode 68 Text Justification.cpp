// LeetCode 68 Text Justification.cpp

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int begin = 0, width = 0;
        for (int i = 0; i < words.size(); i++) {
            if (width + words[i].size() + i - begin - 1 >= maxWidth) {
                ans.push_back("");
                if (i - begin <= 1) {
                    ans.back() += words[begin];
                    ans.back() += string(maxWidth - ans.back().size(), ' ');
                } else {
                    int quo = (maxWidth - width) / (i - begin - 1);
                    int rem = (maxWidth - width) % (i - begin - 1);
                    for (int j = begin; j < i - 1; j++) {
                        ans.back() += words[j];
                        ans.back() += string(j < begin + rem ? quo + 1 : quo, ' ');
                    }
                    ans.back() += words[i - 1];
                }
                begin = i;
                width = 0;
            }
            width += words[i].size();
        }
        ans.push_back("");
        for (int i = begin; i < words.size() - 1; i++) {
            ans.back() += words[i];
            ans.back() += " ";
        }
        ans.back() += words.back();
        ans.back() += string(maxWidth - ans.back().size(), ' ');
        return ans;
    }
};