class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> myMap;

        for(int i=0;i<s.length();i++) {
            myMap[s[i]]++;
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        for(auto it: myMap) {
            pq.push({it.second, it.first});
        }

        string result = "";
        while (!pq.empty()) {
            auto [freq, ch] = pq.top();
            result += string(freq, ch); 
            pq.pop();
        }
        return result;
    }
};