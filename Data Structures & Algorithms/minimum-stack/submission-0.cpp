class MinStack {
private:
    vector<pair<int, int>> mp;

public:
    MinStack() {

    }
    
    void push(int val) {
        if (mp.empty())
            mp.push_back({val, val});
        else 
            mp.push_back({val, min(mp.back().second, val)});
    }
    
    void pop() {
        mp.pop_back();
    }
    
    int top() {
        return mp.back().first;
    }
    
    int getMin() {
        return mp.back().second;
    }
};
