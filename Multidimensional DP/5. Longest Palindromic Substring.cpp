class Solution {
public:
    string longestPalindrome(string s) {

        int len = 0;
        int idx = -1;

        for (int i = 0; i < s.length(); ++i) {


            int l = i;
            int r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (len <  r - l + 1) {
                    len = r - l + 1;
                    idx = l;
                } 
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (len <  r - l + 1) {
                    len = r - l + 1;
                    idx = l;
                } 
                l--;
                r++;
            }

        }

        return s.substr(idx, len);
    }
};

===========

two ptr hai!
