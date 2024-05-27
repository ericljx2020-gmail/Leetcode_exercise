class LUPrefix {
public:
    unordered_set<int> hash;
    int x;
    //由于前缀长度只会增加不会减少，所以用一个x来从小到大进行维护
    //在1被upload之前，longest永远return 0，因为x不会更新
    //如果1一旦进来，就可以找到之前记录过的跟1连接的点。
    LUPrefix(int n) {
        x = 1;
    }
    
    void upload(int video) {
        if (hash.count(video) == 0){
            hash.insert(video);
        }
    }
    
    int longest() {
        while (hash.find(x) != hash.end()){
            x++;
        }
        return x - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */