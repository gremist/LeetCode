// LeetCode 150 Evaluate Reverse Polish Notation.cpp

// 方法1：迭代
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        stack<int> s;
        for (string &t : tokens) {
            if (t.size() > 1 || isdigit(t[0])) {
                s.push(stoi(t));
            } else {
                int rhs = s.top();
                s.pop();
                int lhs = s.top();
                s.pop();
                s.push(m[t[0]](lhs, rhs));
            }
        }
        return s.top();
    }
    
private:
    unordered_map<char, function<int(int, int)>> m = {
        {'+', plus<int>()},       {'-', minus<int>()},
        {'*', multiplies<int>()}, {'/', divides<int>()}
    };
};

// 方法2：递归
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        
        string back = tokens.back();
        tokens.pop_back();
        if (back.size() > 1 || isdigit(back[0])) {
            return stoi(back);
        }
        
        int rhs = evalRPN(tokens);
        int lhs = evalRPN(tokens);
        return m[back[0]](lhs, rhs);
    }
    
private:
    unordered_map<char, function<int(int, int)>> m = {
        {'+', plus<int>()},       {'-', minus<int>()},
        {'*', multiplies<int>()}, {'/', divides<int>()}
    };
};