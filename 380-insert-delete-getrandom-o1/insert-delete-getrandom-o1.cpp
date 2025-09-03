class RandomizedSet {
public:
    unordered_map<int, int> hash;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (hash.count(val) != 0) return false;
        hash[val] = nums.size();
        nums.push_back(val);
        return true;   
    }
    
    bool remove(int val) {
        if (hash.count(val) == 0) return false;
        int current_p = hash[val];
        int last_val = nums[nums.size()-1];
        swap(nums[current_p], nums[nums.size()-1]);
        hash[last_val] = current_p;
        nums.pop_back();
        hash.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */