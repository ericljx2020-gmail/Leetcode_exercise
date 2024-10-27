class MovingAverage {
public:
    deque<int> q;
    int n;
    double sum = 0;
    MovingAverage(int size) {
        n = size;
    }
    
    double next(int val) {
        if (q.size() == n) {
            sum -= q.front();
            q.pop_front();
        }
        sum += val;
        q.push_back(val);
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */