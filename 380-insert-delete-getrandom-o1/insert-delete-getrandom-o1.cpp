class RandomizedSet {
public:
    unordered_map<int,int> hash;
    vector<int> res;
    RandomizedSet() {
        res.push_back(0);
    }
    
    bool insert(int val) {
        if (hash[val]) return false;
        res.push_back(val);
        hash[val] = res.size()-1;
        return true;
    }
    
    bool remove(int val) {
        int pos = hash[val];
        hash[val] = 0;
        if (pos == 0) return false;
        res.erase(res.begin()+pos);
        for (int i = pos; i < res.size(); i++){
            hash[res[i]] = i;
        }
        return true;
    }
    
    int getRandom() {
        return res[1+rand() % (res.size()-1)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */