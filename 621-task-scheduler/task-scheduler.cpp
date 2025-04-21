class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>, vector<pair<int, char>>> maxHeap;
        int totalTime = 0;
        unordered_map<char, int> freq;

        for (char c : tasks) {
            freq[c]++;
        }

        for(auto it : freq){
            maxHeap.push({it.second, it.first});   
        }

        while (!maxHeap.empty()) {
            vector<pair<int, char>> temp;
            int cycle = 0;

            for (int i = 0; i <= n; ++i) {
                if (!maxHeap.empty()) {
                    auto [cnt, ch] = maxHeap.top();
                    maxHeap.pop();
                    cycle++;

                    if (cnt > 1) temp.push_back({cnt - 1, ch}); 
                }
            }

            for (auto& p : temp) {
                maxHeap.push(p);
            }

            totalTime += maxHeap.empty() ? cycle : (n + 1); 
        }
        return totalTime;
    }
};

// A A A B B B, n = 3
// I think first we gotta store the freq of every char in pq, lets say 
// pg of pair of char and int so we get A 3, B 3, By default it'll coompare the chars ascii
// so first out would be A, so now leeft with A 2, B 3.
// Create an array to store based on indexes.
// First is A, now we pop next from pq, which again is A, so lets place it at +nth position in arr
// Do it one more time.
// Now we left with A 0 B 3
// B comes out, and do same as A jumping, +n times for each. 
// Return the size of newly created array.
// You'll need pq cuz you're taking out same chars first.
//to get the size of resault array, in worst case lets say all elems are same A A A A A, n = 3
// then size would be A _ _ _ A _ _ _ A _ _ _ A _ _ _ A so 17 hence max of n * size of arry + 1
// But this would increase the space, hence we keep a totalTime var and count in terms of cycles of length n+1.

// A B _ _ A B _ _ A B
