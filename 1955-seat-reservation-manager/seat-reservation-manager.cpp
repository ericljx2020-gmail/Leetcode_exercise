class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>>heap;
    SeatManager(int n) {
        for (int i = 1; i <= n; i++){
            heap.push(i);
        }
    }
    
    int reserve() {
        int res = heap.top();
        heap.pop();
        return res;
    }
    
    void unreserve(int seatNumber) {
        heap.push(seatNumber);
        return;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */