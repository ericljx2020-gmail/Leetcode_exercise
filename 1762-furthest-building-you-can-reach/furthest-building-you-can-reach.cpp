class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int l = 0, r = n-1;
        vector<int> diff;
        for (int i = 0; i < n; i++){
            if (i == 0) diff.push_back(0);
            else diff.push_back(max(0, heights[i] - heights[i-1]));
            cout << diff[i] << " ";
        }
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (check(mid, heights, bricks, ladders, diff)){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        // check(8, heights, bricks, ladders, diff);
        return r;
    }

    bool check(int p, vector<int> heights, int bricks, int ladders, vector<int> diff){
        priority_queue<int> pq;
        for (int i = 0; i <= p; i++){
            if (diff[i] != 0) pq.push(diff[i]);
        }
        while (pq.size()){
            int t = pq.top();
            pq.pop();
            // cout << t << " " << ladders << " " << bricks << "\n";
            if (ladders){
                ladders--;
            }else if (bricks){
                bricks -= t;
            }else{
                return false;
            }
        }
        return (ladders >= 0 && bricks >= 0);
    }
};