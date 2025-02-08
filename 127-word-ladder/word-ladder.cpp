class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> mySet;

        for(auto i : wordList) {
            mySet.insert(i);
        }

        if(mySet.find(endWord) == mySet.end())  return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            auto temp = q.front();
            string oper = temp.first;
            int len = temp.second;

            q.pop();

            for(int i=0;i<oper.length();i++) {
                string copyOper = oper;
                for(char it = 'a'; it<='z';it++) {
                    copyOper[i] = it;

                    if(copyOper == endWord) return len+1;
                    // found
                    if(mySet.find(copyOper) != mySet.end()){
                        q.push({copyOper, len + 1});
                        mySet.erase(copyOper);
                    }
                }
            }
        }
        return 0;
    }
};