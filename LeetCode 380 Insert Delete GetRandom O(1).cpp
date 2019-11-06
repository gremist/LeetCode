// LeetCode 380 Insert Delete GetRandom O(1).cpp

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() : dre(time(0)) {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        v.push_back(val);
        m[val] = v.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        v[m[val]] = v.back();
        m[v.back()] = m[val];
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution<int> uid(0, v.size() - 1);
        return v[uid(dre)];
    }
    
private:
    default_random_engine dre;
    vector<int> v;
    unordered_map<int, int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */