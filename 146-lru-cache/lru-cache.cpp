class LRUCache {
public:

    struct Node{
        int key, val;
        Node *left, *right;
        Node(int key, int val) {
            this -> key = key;
            this -> val = val;
            this -> left = NULL;
            this -> right = NULL;
        }
    }*L, *R;            //初始化两个dummy nodes
    
    unordered_map<int, Node*> hash;         //存储key对应的Node
    int n;              //capacity

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

    LRUCache(int capacity) {
        L = new Node(0,0);
        R = new Node(0,0);
        L -> right = R;
        R -> left = L;
        n = capacity;
    }
    
    int get(int key) {
        if (hash.count(key) != 0){
            auto p = hash[key];
            remove(p);                //从当前位置移除
            insert(p);                //插入回最左边
            return p -> val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (hash.count(key) != 0){
            //当前key之前出现过只需要修改值
            auto p = hash[key];
            p -> val = value;
            remove(p);
            insert(p);
        }else{
            //当前key是第一次出现
            if (hash.size() == n){
                auto p = R -> left;
                //说明到了capacity
                remove(p);
                hash.erase(p -> key);
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