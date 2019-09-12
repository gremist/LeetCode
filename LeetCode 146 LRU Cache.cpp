// LeetCode 146 LRU Cache.cpp

class LRUCache {
public:
    LRUCache(int capacity) : c(capacity) {

    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            update(key);
            return m[key][0];
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            update(key);
            m[key][0] = value;
            return;
        }
        push(key, value);
        if (m.size() > c + 1) {
            pop();
        }
    }
    
private:
    void push(int key, int value) {
        m[key] = {value, m[-1][1], -1};
        m[m[-1][1]][2] = key;
        m[-1][1] = key;
    }
    
    void pop() {
        int key = m[-1][2];
        m[-1][2] = m[key][2];
        m[m[key][2]][1] = -1;
        m.erase(key);
    }
    
    void update(int key) {
        m[m[key][1]][2] = m[key][2];
        m[m[key][2]][1] = m[key][1];
        m[key][1] = m[-1][1];
        m[key][2] = -1;
        m[m[-1][1]][2] = key;
        m[-1][1] = key;
    }
    
private:
    int c;
    unordered_map<int, vector<int>> m = {
        {-1, {0, -1, -1}}
    };
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */