class SnapshotArray {
public:
    int id = 0;
    unordered_map<int, vector<pair<int, int>>> hash;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        hash[index].push_back({val, id});
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        int n = hash[index].size();
        if (n == 0) return 0;
        int l = 0, r = n-1;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (hash[index][mid].second <= snap_id){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        if (hash[index][r].second <= snap_id) return hash[index][r].first;
        else return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */