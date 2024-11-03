class RandomizedSet {
    vector<int> v;
    unordered_map<int, int> hash;
public:
    RandomizedSet() {
        
    }

    bool search(int val){
        return hash.find(val) != hash.end();
    }
    
    bool insert(int val) {
        if (search(val)) return false;
        v.push_back(val);
        hash[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (!search(val)) return false;
        v[hash[val]] = v[v.size()-1];
        v.pop_back();
        hash[v[hash[val]]] = hash[val];
        hash.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */