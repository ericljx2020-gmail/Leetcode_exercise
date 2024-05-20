class LRUCache {
public:

    struct Node{
        int key, val;
        Node* left, *right;
        Node(int key, int val) : key(key), val(val) {}
    }*L,*R;

    int capacity;
    unordered_map<int, Node*> hash;
    
    LRUCache(int _capacity) {
        capacity = _capacity;
        L = new Node(-1,-1);
        R = new Node(-1,-1);
        L -> right = R;
        R -> left = L;
    }

    void insert(Node* p) {
        p -> right = L -> right;
        p -> left = L;
        L -> right -> left = p;
        L -> right = p;
    }

    void remove(Node* p) {
        p -> left -> right = p -> right;
        p -> right -> left = p -> left;
    }
    
    int get(int key) {
        if (hash.count(key)){
            //说明已经有了
            auto p = hash[key];
            remove(p);
            insert(p);
            return p -> val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (hash.count(key)){
            //说明已经存在，修改值即可，不用考虑超出capacity
            auto p = hash[key];
            p -> val = value;
            remove(p);
            insert(p);
        }else{
            //说明不存在要判断
            if (hash.size() == capacity) {
                auto p = R -> left;
                hash.erase(p -> key);
                remove(p);
            }
            auto p = new Node(key, value);
            insert(p);
            hash[key] = p;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */