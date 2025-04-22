class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        if(s.size() == 0) return 0;

        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int p1 = 0, p2 = 0, result = 0;

        while(p1 < n && p2 < m){
            if(s[p2] >= g[p1]) {
                result++;
                p1++;
                p2++;
            }else if(s[p2] < g[p1]){
                p2++;
            }
        }
        return result;
    }
};

// 3 child, each with some greed measure by g called greed factor. Which means that child can have that sized cookie to satisfy their hunger. 
// Cookie s is the size of cookies given, where each cookie can only be given to one child. 
// So s[i] >= g[j] to satisfy the child
// g = [1, 2, 3] || s = [1, 1]
// So we can give first cokie of size 1 to child 1, then we cannot give the rem cookie to any child, hence return 1

// g = [2, 4, 2, 7 , 1] || s = [1, 4, 3, 2, 8]
// Sort both first
// g = [1, 2, 2, 4, 7] || s = [1, 2, 3, 4, 8]
// now assign cookie to child matching the indexes, 
// 1>=1, 2>=2, 3>=2, 4>=4, 8>=7, return 5


// Is this the edge case, lets say at index 2, the cookie is not greater the size then gree dfactor but at index 3 it is, can we use that instead?
// 1, 1, 2, 2 && 1, 1, 1, 3, 3
// 1>=1, 1>=1 but 1<2, 3>=2