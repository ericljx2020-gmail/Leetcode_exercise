class LRUCache {
public:

    struct Node{
        int key, val;
        Node *left, *right;
        Node(int key, int val){
            this -> key = key;
            this -> val = val;
        }
    }*L, *R;                //two dummy nodes

    int n;
    unordered_map<int, Node*> hash;

    void insert(auto p){
        p -> right = L -> right;
        p -> left = L;
        L -> right = p;
        p -> right -> left = p;
    }

    void remove(auto p) {
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
            //说明存在,返回val的同时更新Node位置
            auto p = hash[key];
            remove(p);              //从当前位置删除
            insert(p);              //插入队列头部
            return(p -> val);
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (hash.count(key) != 0){
            //说明存在当前key，需要修改val
            auto p = hash[key];
            p -> val = value;
            remove(p);
            insert(p);
        }else{
            //说明当前key是第一次加入队列
            if (hash.size() == n){
                //如果已经满capacity删除最右边的节点
                auto p = R -> left;
                remove(p);
                hash.erase(p -> key);
            }
            auto p = new Node(key, value);
            insert(p);
            hash[p -> key] = p;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */