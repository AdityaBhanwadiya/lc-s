class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto it : freq) {
            minHeap.push(it.first);
        }

        while (!minHeap.empty()) {
            int first = minHeap.top();
            minHeap.pop();

            if (freq[first] == 0) continue;

            int count = freq[first];
            for (int i = 0; i < groupSize; ++i) {
                int curr = first + i;
                if (freq[curr] < count) return false;
                freq[curr] -= count;
            }
        }

        return true;
    }
};
