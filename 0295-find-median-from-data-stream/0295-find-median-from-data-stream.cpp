class MedianFinder {

    priority_queue<int> left;                               // max heap, smaller half
    priority_queue<int, vector<int>, greater<int>> right;   // min heap, larger half

public:
    MedianFinder() {}
    
    void addNum(int num) {
        left.push(num);

        if(!right.empty() && left.top() > right.top()){
            right.push(left.top());
            left.pop();
        }

        // rebalance sizes — right holds extra
        if(right.size() > left.size() + 1){
            left.push(right.top());
            right.pop();
        }
        else if(left.size() > right.size()){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        return (left.size() == right.size()) ? 
                (left.top() + right.top()) / 2.0 : right.top();  // right has extra when odd
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */