class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        int n = hand.size();
        if (n % gs != 0) return false;
        unordered_map<int, int> hash;
        for (auto h : hand){
            hash[h]++;
        }
        sort(hand.begin(), hand.end());
        hand.erase(unique(hand.begin(), hand.end()), hand.end());
        for (auto h : hand){
            while (hash[h]){
                for (int i = 0; i < gs; i++){
                    if (hash[h+i] == 0) return false;
                    hash[h+i]--;
                }
            }
        }
        return true;
    }
};