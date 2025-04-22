class MedianFinder {
public: 
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    // 7 3 8 | 1 0 3 7 | 2
    // maxHeap = 3 8
    // minHeap = 7
    void addNum(int num) {
        maxHeap.push(num);
        
        int top = maxHeap.top();
        maxHeap.pop();
        
        minHeap.push(top);
        if (minHeap.size() > maxHeap.size()) {
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }

    }
    
    double findMedian() {
        int totalSize = maxHeap.size() + minHeap.size();

        if (totalSize % 2 == 0) {
            return (double)(maxHeap.top() + minHeap.top()) / 2;
        } else {
            return (double)maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */