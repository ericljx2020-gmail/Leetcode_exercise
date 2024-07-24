class TimeMap {
public:
    unordered_map<string, vector<int>> hash;
    unordered_map<string, unordered_map<int, string>> Map;
    TimeMap() {
        int a = 0;
    }
    
    void set(string key, string value, int timestamp) {
        int n = hash[key].size();
        if (n == 0) hash[key].push_back(timestamp);
        else{
            int l = 0, r = n-1;
            while (l < r){
                int mid = l + r >> 1;
                if (hash[key][mid] >= timestamp){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            if (hash[key][r] >= timestamp) hash[key].insert(hash[key].begin()+r, timestamp);
            else hash[key].push_back(timestamp);
        }
        Map[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // for (auto c : hash[key]) cout << c << " ";
        // cout << ":::";
        // return "";
        int n = hash[key].size();
        if (n == 0) return "";
        int l = 0, r = n-1;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (hash[key][mid] <= timestamp){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        // cout << r << " " << Map[key][hash[key][r]] << '\n';
        if (hash[key][r] <= timestamp) return Map[key][hash[key][r]];
        else return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */