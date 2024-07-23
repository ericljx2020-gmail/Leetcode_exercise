class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> hash;
    vector<int> arr;
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> cache;
    RangeFreqQuery(vector<int>& _arr) {
        arr = _arr;
        for (int i = 0; i < arr.size(); i++){
            hash[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if (cache[left][right][value]) return cache[left][right][value];
        vector<int> cur = hash[value];
        if (cur.size() == 0) return 0;
        //找左端点
        if (left > cur[cur.size()-1] || right < cur[0]) return 0;
        int l = 0, r = cur.size()-1;
        while (l < r){
            int mid = l + r >> 1;
            if (cur[mid] >= left){
                r = mid;
            }else{
                l = mid+1;
            }
        }

        int ll = r;
        l = 0, r = cur.size()-1;
        //找右端点
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (cur[mid] <= right){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        // cout << r << " " << l << endl;
        cache[left][right][value] = max(0, r-ll+1);
        return max(0, r-ll+1);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */