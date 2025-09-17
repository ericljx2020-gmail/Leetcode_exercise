class LRUCache {
public:

    struct Node{
        int key, val;
        Node* left, *right;
        Node(int _key, int _val) : key(_key), val(_val) {};
    }*L, *R;
    int capacity;
    unordered_map<int, Node*> hash;
    LRUCache(int _capacity) {
        L = new Node(-1,-1);
        R = new Node(-1,-1);
        L -> right = R;
        R -> left = L;
        capacity = _capacity;
    }

    void insert(Node* p){
        p -> right = L -> right;
        L -> right -> left = p;
        p -> left = L;
        L -> right = p;
    }

    void remove(Node* p){
        p -> left -> right = p -> right;
        p -> right -> left = p -> left;
    }
    
    int get(int key) {
        if (hash.count(key)){
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
            auto p = hash[key];
            p -> val = value;
            remove(p);
            insert(p);
        }else{
            if (hash.size() == capacity){
                auto r = R -> left;
                hash.erase(r -> key);
                remove(r);
            }
            Node* p = new Node(key, value);
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