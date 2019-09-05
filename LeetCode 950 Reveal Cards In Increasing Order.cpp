// LeetCode 950 Reveal Cards In Increasing Order.cpp

// 方法1：模拟
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int ds = deck.size();
        queue<int> q;
        for (int i = 0; i < ds; i++) {
            q.push(i);
        }
        
        sort(deck.begin(), deck.end());
        vector<int> ans(ds);
        for (int i = 0; i < ds - 1; i++) {
            ans[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        ans[q.front()] = deck.back();
        return ans;
    }
};

// 方法2：逆推
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int ds = deck.size();
        sort(deck.begin(), deck.end());
        
        queue<int> q;
        q.push(deck.back());
        for (int i = ds - 2; i >= 0; i--) {
            q.push(q.front());
            q.pop();
            q.push(deck[i]);
        }
        
        for (int i = ds - 1; i >= 0; i--) {
            deck[i] = q.front();
            q.pop();
        }
        return deck;
    }
};