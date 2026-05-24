class Solution {
public:
    bool isAlphaNumeric(char c) {
        if (
            (0 <= (c - 'a') && (c - 'a') <= 25) ||
            (0 <= (c - 'A') && (c - 'A') <= 25) ||
            (0 <= (c - '0') && (c - '0') <= 9) 
        )
        {
            return true; 
        }

        return false;
    }

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (0 <= (c - 'A') && (c - 'A') <= 25) {
                s[i] = 'a' + (c - 'A');
            }
        }

        while (i < j) {
            bool l = isAlphaNumeric(s[i]);
            bool r = isAlphaNumeric(s[j]);

            if (l && r) {

                if (s[i] != s[j]) {
                    return false;
                } else {
                    i++;
                    j--;
                }
            } else if (!l && !r) {
                j--;
                i++;
            } else if (!r) {
                j--;
            } else if (!l) {
                i++;
            }
        }

        return true;
    }
};

======
better is to use mulitple if blocks instead of else if
