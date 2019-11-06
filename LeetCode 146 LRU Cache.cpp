// LeetCode 146 LRU Cache.cpp

class LRUCache {
public:
    LRUCache(int capacity) : c(capacity) {

    }

    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        int value = m[key]->second;
        l.erase(m[key]);
        l.emplace_front(key, value);
        m[key] = l.begin();
        return value;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            l.erase(m[key]);
        }
        l.emplace_front(key, value);
        m[key] = l.begin();
        if (l.size() > c) {
            m.erase(l.back().first);
            l.pop_back();
        }
    }

private:
    int c;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */