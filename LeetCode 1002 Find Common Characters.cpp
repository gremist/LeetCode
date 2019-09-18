// LeetCode 1002 Find Common Characters.cpp

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> ht1(26);
        for (char ch : A[0]) {
            ht1[ch - 'a']++;
        }
        
        for (int i = 1; i < A.size(); i++) {
            vector<int> ht2(26);
            for (char ch : A[i]) {
                ht2[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                ht1[i] = min(ht1[i], ht2[i]);
            }
        }
        
        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < ht1[i]; j++) {
                ans.emplace_back(1, i + 'a');
            }
        }
        return ans;
    }
};