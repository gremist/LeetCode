// LeetCode 705 Design HashSet.cpp

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : v(1000000, false) {
        
    }
    
    void add(int key) {
        v[key] = true;
    }
    
    void remove(int key) {
        v[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return v[key];
    }
    
private:
    vector<bool> v;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */