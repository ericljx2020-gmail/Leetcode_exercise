class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& p, int capacity) {
        sort(buses.begin(), buses.end());
        sort(p.begin(), p.end());
        vector<int> v, b;
        for (int i = 0, j = 0; i < buses.size(); i++){
            int t = buses[i];
            int cur = 0;
            while (j < p.size() && p[j] <= t && cur < capacity){
                v.push_back(p[j]);
                cur++;
                j++;
            }
            if (cur == capacity) b.push_back(true);
            else b.push_back(false);
        }
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        if (v.size() == 0) return buses[buses.size()-1];
        if (b[b.size()-1]){
            for (int i = v.size()-2; i >= 0; i--){
                if (v[i] != v[i+1]-1){
                    return v[i+1]-1;
                }
            }
            return v[0]-1;
        }else{
            if (buses[buses.size()-1] == v[v.size()-1]){
                for (int i = v.size()-2; i >= 0; i--){
                    if (v[i] != v[i+1]-1){
                        return v[i+1]-1;
                    }
                }
                return v[0]-1;
            }else{
                return buses[buses.size()-1];
            }
        }
        return 0;
    }
};