class Solution {
private:
    string findPrefix(string s, string t) {
        int i=0, j=0;
        while(i<s.length() && j<t.length()) {
            if(s[i] != t[j]){
                break;
            }else{
                i++;j++;
            }
        }
        return s.substr(0,i);
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for(int i=1;i<strs.size();i++) {
            prefix = findPrefix(prefix, strs[i]);
        }
        return prefix;
    }
};
