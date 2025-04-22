class KthLargest {
public:
    int k = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            add(num); 
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        while(minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

// 4 5 8 2
// 4 5 8 2 3 -> 4
// 4 5 8 2 3 5 -> 5
// 4 5 8 2 3 5 10 -> 5
//.....

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */