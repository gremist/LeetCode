// LeetCode 20 Valid Parentheses.cpp

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) return false;
        stack<char> left_stack;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                left_stack.push(ch);
            } else if (left_stack.empty() ||
                left_stack.top() == '(' && ch != ')' ||
                left_stack.top() == '[' && ch != ']' ||
                left_stack.top() == '{' && ch != '}') {
                return false;
            } else {
                left_stack.pop();
            }
        }
        return left_stack.empty();
    }
};