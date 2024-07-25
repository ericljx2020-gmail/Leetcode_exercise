class TopVotedCandidate {
public:
    vector<pair<int,int>>record;
    unordered_map<int, int> hash;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int val = 0;
        int n = persons.size();
        for (int i = 0; i < n; i++){
            int p = persons[i];
            int t = times[i];
            hash[p]++;
            if (hash[p] >= val){
                val = hash[p];
                record.push_back({p, t});
            }
        }
    }
    
    int q(int t) {
        int n = record.size();
        int l = 0, r = n-1;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (record[mid].second <= t){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        return record[r].first;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */