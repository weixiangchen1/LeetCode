class MyHashSet {
public:
    MyHashSet() {}
    
    void add(int key) {
        Hash.insert(key);
    }
    
    void remove(int key) {
        Hash.erase(key);
    }
    
    bool contains(int key) {
        return Hash.count(key);
    }

private:
    unordered_set<int> Hash;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
