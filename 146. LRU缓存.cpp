class LRUCache {
public:
    struct Node {
        int _key;
        int _val;
        Node* _next;
        Node* _prev;
        Node(int key, int val): _key(key), _val(val), _next(nullptr), _prev(nullptr) {}
    }*head, *tail;
    unordered_map<int, Node*> _hash;
    int _capacity;

public:
    LRUCache(int capacity) {
        _capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->_next = tail;
        tail->_prev = head;
    }
    
    void remove(Node* p) {
        p->_next->_prev = p->_prev;
        p->_prev->_next = p->_next;
    }

    void insert(Node* p) {
        p->_next = head->_next;
        p->_prev = head;
        head->_next->_prev = p;
        head->_next = p;
    }

    int get(int key) {
        if (_hash.count(key) == 0) {
            return -1;
        }
        Node* p = _hash[key];
        remove(p);
        insert(p);
        return p->_val;
    }
    
    void put(int key, int value) {
        // 哈希表中已有key值
        if (_hash.count(key)) {
            Node* p = _hash[key];
            p->_val = value;
            remove(p);
            insert(p);
        }
        else {
            // 超出最大容量          
            if (_hash.size() == _capacity) {
                Node* p = tail->_prev;
                remove(p);
                _hash.erase(p->_key);
                delete p;
            }
            Node* newNode = new Node(key, value);
            _hash[key] = newNode;
            insert(newNode);
        }
    }   
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
