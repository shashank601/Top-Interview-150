class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> v(numRows);
        
        int x = 0;
        int dir = 1;
        for (int i = 0; i < s.length(); i++) {
            v[x].push_back(s[i]);
            
            if (x == 0)
                dir = 1;
            
            if (x == numRows - 1)
                dir = -1;

            x += dir;
            
        }

        string ans = "";
        for (auto& s : v) {
            ans += s;
        }

        return ans;
    }
};

========

requirement:

a var that osicallate b/w 0 to n 

0 to n to 0 to n to 0 ...

i = 0
dir = 1
for () {

  if (x == 0) dir = 1;

  if (x == n - 1) dir = -1;           <-- use else if or add edge case check n = 1

  x += dir;
  

}
